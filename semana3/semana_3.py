import threading
import time  # Importa o módulo time para medir o tempo de execução

def sum_part(numbers, start, end, results, index):
    total = sum(numbers[start:end])
    results[index] = total

if __name__ == "__main__":
    # Defina os diferentes casos de teste para a lista de números
    test_cases = [
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],  # Teste 1
        list(range(1, 10000)),            # Teste 2
        list(range(1, 10000001))          # Teste 3
    ]

    for case_index, numbers in enumerate(test_cases, start=1):
        print(f"\nExecutando Teste {case_index}...")

        # Inicia a medição do tempo
        start_time = time.time()

        # Calcula a soma total sem o uso de threads
        total_sum = 0
        for i in numbers:
            total_sum += i

        # Finaliza a medição do tempo
        end_time = time.time()

        print(f"A soma total é: {total_sum}")
        print(f"Tempo de execução sem threads: {end_time - start_time:.6f} segundos")

        num_threads = 2  # Altere este valor para testar com mais threads

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

        total_sum = sum(results)

        # Finaliza a medição do tempo
        end_time = time.time()

        print(f"A soma total é: {total_sum}")
        print(f"Tempo de execução com threads: {end_time - start_time:.6f} segundos")
