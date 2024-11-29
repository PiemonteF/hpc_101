#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
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
        clock_t inicio = clock();

        // Cálculo da soma de forma serial
        for (i = 0; i < N; i++) {
            soma += vetor[i];
        }

        // Finaliza a medição do tempo
        clock_t fim = clock();

        double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Teste %d - Tamanho do vetor: %d\n", t+1, N);
        printf("Soma Serial: %lld\n", soma);
        printf("Tempo de execução sem OpenMP: %f segundos\n\n", tempo_total);

        free(vetor);
    }
    return 0;
}
