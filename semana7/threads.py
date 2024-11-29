import threading
import time
import random  # Para gerar números aleatórios

def sum_part(numbers, start, end, results, index):
    """Calcula a soma de uma parte do vetor."""
    total = sum(numbers[start:end])
    results[index] = total

if __name__ == "__main__":
    # Tamanhos dos vetores para os testes
    tamanhos = [1000000, 10000000, 50000000, 100000000]
    num_threads = 4  # Número de threads a serem usadas

    for t, N in enumerate(tamanhos, start=1):
        print(f"\nExecutando Teste {t} - Tamanho do vetor: {N}...")

        # Gerando o vetor com números inteiros aleatórios entre 0 e 99
        numbers = [random.randint(0, 99) for _ in range(N)]

        # Soma paralela usando threads
        part_size = len(numbers) // num_threads
        results = [0] * num_threads
        threads = []

        # Inicia a medição do tempo
        start_time = time.time()

        for i in range(num_threads):
            start = i * part_size
            if i == num_threads - 1:
                end = len(numbers)
            else:
                end = (i + 1) * part_size
            t = threading.Thread(target=sum_part, args=(numbers, start, end, results, i))
            threads.append(t)
            t.start()

        for t in threads:
            t.join()

        total_sum_parallel = sum(results)

        # Finaliza a medição do tempo
        end_time = time.time()

        print(f"Soma Paralela com {num_threads} threads: {total_sum_parallel}")
        print(f"Tempo de execução com threads: {end_time - start_time:.6f} segundos")
