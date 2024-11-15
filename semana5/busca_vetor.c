#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

// Função para encontrar o maior valor de forma serial
int encontra_maior_serial(int *vetor, int tamanho) {
    int maior = vetor[0];
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

// Função para encontrar o maior valor de forma paralela
int encontra_maior_paralelo(int *vetor, int tamanho) {
    int maior_global = 0;
    
    #pragma omp parallel
    {
        int maior_local = vetor[0];
        
        #pragma omp for
        for(int i = 0; i < tamanho; i++) {
            if(vetor[i] > maior_local) {
                maior_local = vetor[i];
            }
        }
        
        #pragma omp critical
        {
            if(maior_local > maior_global) {
                maior_global = maior_local;
            }
        }
    }
    return maior_global;
}

int main() {
    // Array com diferentes tamanhos para teste
    int tamanhos[] = {1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    printf("Comparação entre execução Serial e Paralela:\n");
    printf("%-12s %-15s %-15s %-15s\n", "Tamanho", "Serial (s)", "Paralelo (s)", "Speedup");
    printf("------------------------------------------------\n");

    for(int t = 0; t < num_testes; t++) {
        int N = tamanhos[t];
        int *vetor = (int*)malloc(N * sizeof(int));
        
        // Inicializa o vetor
        srand(time(NULL));
        for(int i = 0; i < N; i++) {
            vetor[i] = rand() % 10000;
        }

        // Teste Serial
        double inicio_serial = omp_get_wtime();
        int maior_serial = encontra_maior_serial(vetor, N);
        double tempo_serial = omp_get_wtime() - inicio_serial;

        // Teste Paralelo
        double inicio_paralelo = omp_get_wtime();
        int maior_paralelo = encontra_maior_paralelo(vetor, N);
        double tempo_paralelo = omp_get_wtime() - inicio_paralelo;

        // Calcula o speedup
        double speedup = tempo_serial / tempo_paralelo;

        printf("%-12d %-15f %-15f %-15f\n", 
               N, tempo_serial, tempo_paralelo, speedup);

        free(vetor);
    }

    return 0;
}