import cupy as cp
import numpy as np
import time

# Configurações iniciais
tamanhos = [1_000_000, 10_000_000, 50_000_000, 100_000_000]  # Tamanhos dos vetores

for t, N in enumerate(tamanhos):
    # Cria o vetor na GPU com números inteiros aleatórios entre 0 e 99
    vetor = cp.random.randint(0, 100, size=N, dtype=cp.int32)
    
    # Inicializa a soma
    soma = cp.array(0, dtype=cp.int64)

    # Inicia a medição do tempo
    inicio = time.time()

    # Soma paralela na GPU
    soma = cp.sum(vetor)

    # Finaliza a medição do tempo
    fim = time.time()

    # Transferência do resultado da GPU para a CPU
    soma_host = soma.get()

    print(f"Teste {t+1} - Tamanho do vetor: {N}")
    print(f"Soma Paralela: {soma_host}")
    print(f"Tempo de execução com CuPy: {fim - inicio:.6f} segundos\n")
