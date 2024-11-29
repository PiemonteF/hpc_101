#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <time.h>

// Kernel to compute partial sums on the GPU
__global__ void partial_sum(int *d_vetor, long long *d_partial_sums, int N) {
    extern __shared__ long long sdata[];
    int tid = threadIdx.x; // Thread ID within the block
    int i = blockIdx.x * blockDim.x + threadIdx.x; // Global thread ID

    // Load elements into shared memory
    sdata[tid] = (i < N) ? d_vetor[i] : 0;
    __syncthreads();

    // Perform reduction in shared memory
    for (int s = blockDim.x / 2; s > 0; s >>= 1) {
        if (tid < s) {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    // Write the result of this block to the partial sums array
    if (tid == 0) {
        d_partial_sums[blockIdx.x] = sdata[0];
    }
}

int main() {
    // Vector sizes for testing
    int tamanhos[4] = {1000000, 10000000, 50000000, 100000000};
    int num_testes = 4;

    for (int t = 0; t < num_testes; t++) {
        int N = tamanhos[t];
        int *vetor = (int*) malloc(N * sizeof(int));

        // Initialize random number generator
        srand(time(NULL));
        for (int i = 0; i < N; i++) {
            vetor[i] = rand() % 100; // Random numbers between 0 and 99
        }

        // Device memory allocation
        int *d_vetor;
        long long *d_partial_sums;
        int block_size = 256;
        int num_blocks = (N + block_size - 1) / block_size;
        cudaMalloc((void**)&d_vetor, N * sizeof(int));
        cudaMalloc((void**)&d_partial_sums, num_blocks * sizeof(long long));

        // Copy data to device
        cudaMemcpy(d_vetor, vetor, N * sizeof(int), cudaMemcpyHostToDevice);

        // Start timer
        cudaEvent_t start, stop;
        cudaEventCreate(&start);
        cudaEventCreate(&stop);
        cudaEventRecord(start);

        // Launch kernel
        partial_sum<<<num_blocks, block_size, block_size * sizeof(long long)>>>(d_vetor, d_partial_sums, N);

        // Copy partial sums back to host
        long long *partial_sums = (long long*) malloc(num_blocks * sizeof(long long));
        cudaMemcpy(partial_sums, d_partial_sums, num_blocks * sizeof(long long), cudaMemcpyDeviceToHost);

        // Compute final sum on CPU
        long long soma = 0;
        for (int i = 0; i < num_blocks; i++) {
            soma += partial_sums[i];
        }

        // Stop timer
        cudaEventRecord(stop);
        cudaEventSynchronize(stop);
        float milliseconds = 0;
        cudaEventElapsedTime(&milliseconds, start, stop);

        // Output results
        printf("Teste %d - Tamanho do vetor: %d\n", t+1, N);
        printf("Soma Paralela com GPU: %lld\n", soma);
        printf("Tempo de execução com CUDA: %f segundos\n\n", milliseconds / 1000);

        // Free memory
        free(vetor);
        free(partial_sums);
        cudaFree(d_vetor);
        cudaFree(d_partial_sums);
    }

    return 0;
}
