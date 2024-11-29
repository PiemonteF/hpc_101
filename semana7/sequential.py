import time
import random  # Para gerar números aleatórios

if __name__ == "__main__":
    # Tamanhos dos vetores para os testes
    tamanhos = [1000000, 10000000, 50000000, 100000000]

    for t, N in enumerate(tamanhos, start=1):
        print(f"\nExecutando Teste {t} - Tamanho do vetor: {N}...")

        # Gerando o vetor com números inteiros aleatórios entre 0 e 99
        numbers = [random.randint(0, 99) for _ in range(N)]

        # Soma serial
        start_time = time.time()  # Inicia a medição do tempo

        total_sum_serial = sum(numbers)

        end_time = time.time()  # Finaliza a medição do tempo

        print(f"Soma Serial: {total_sum_serial}")
        print(f"Tempo de execução serial: {end_time - start_time:.6f} segundos")
