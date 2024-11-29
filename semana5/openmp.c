#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int num_threads = 4;  // Número de threads a serem utilizadas
    omp_set_num_threads(num_threads);

    // Vetor com diferentes tamanhos para os testes
    int tamanhos[4] = {1000000, 10000000, 50000000, 100000000};
    int num_testes = 4;

    for (int t = 0; t < num_testes; t++) {
        int N = tamanhos[t];  // Tamanho atual do vetor
        int *vetor = (int*) malloc(N * sizeof(int));
        long long soma = 0;
        int i;

        // Inicializa o gerador de números aleatórios
        srand(time(NULL));

        // Preenche o vetor com números inteiros aleatórios
        for (i = 0; i < N; i++) {
            vetor[i] = rand() % 100;  // Números entre 0 e 99
        }

        // Inicia a medição do tempo
        double inicio = omp_get_wtime();

        // Seção paralelizada usando OpenMP
        #pragma omp parallel for reduction(+:soma)
        for (i = 0; i < N; i++) {
            soma += vetor[i];
        }

        // Finaliza a medição do tempo
        double fim = omp_get_wtime();

        printf("Teste %d - Tamanho do vetor: %d\n", t+1, N);
        printf("Soma Paralela com %d threads: %lld\n", num_threads, soma);
        printf("Tempo de execução com OpenMP: %f segundos\n\n", fim - inicio);

        free(vetor);
    }
    return 0;
}
