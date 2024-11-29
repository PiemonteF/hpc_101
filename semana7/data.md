# Cupy

Teste 1 - Tamanho do vetor: 1000000
Soma Paralela: 49479097
Tempo de execução com CuPy: 1.156394 segundos

Teste 2 - Tamanho do vetor: 10000000
Soma Paralela: 494925364
Tempo de execução com CuPy: 0.000118 segundos

Teste 3 - Tamanho do vetor: 50000000
Soma Paralela: 2475298829
Tempo de execução com CuPy: 0.000132 segundos

Teste 4 - Tamanho do vetor: 100000000
Soma Paralela: 4949755462
Tempo de execução com CuPy: 0.000095 segundos

---

# Python Threads

Executando Teste 1 - Tamanho do vetor: 1000000...
Soma Paralela com 4 threads: 49502345
Tempo de execução com threads: 0.014297 segundos

Executando Teste 2 - Tamanho do vetor: 10000000...
Soma Paralela com 4 threads: 495147563
Tempo de execução com threads: 0.092822 segundos

Executando Teste 3 - Tamanho do vetor: 50000000...
Soma Paralela com 4 threads: 2475138719
Tempo de execução com threads: 0.485306 segundos

Executando Teste 4 - Tamanho do vetor: 100000000...
Soma Paralela com 4 threads: 4950041011
Tempo de execução com threads: 0.960033 segundos

---

# CUDA

Teste 1 - Tamanho do vetor: 1000000
Soma Paralela com GPU: 49504078
Tempo de execução com CUDA: 0.014027 segundos

Teste 2 - Tamanho do vetor: 10000000
Soma Paralela com GPU: 495023358
Tempo de execução com CUDA: 0.000392 segundos

Teste 3 - Tamanho do vetor: 50000000
Soma Paralela com GPU: 2475121780
Tempo de execução com CUDA: 0.001723 segundos

Teste 4 - Tamanho do vetor: 100000000
Soma Paralela com GPU: 4949740356
Tempo de execução com CUDA: 0.004394 segundos

---

# OpenMP

Teste 1 - Tamanho do vetor: 1000000
Soma Paralela com 4 threads: 49472445
Tempo de execução com OpenMP: 0.001950 segundos

Teste 2 - Tamanho do vetor: 10000000
Soma Paralela com 4 threads: 494998960
Tempo de execução com OpenMP: 0.010306 segundos

Teste 3 - Tamanho do vetor: 50000000
Soma Paralela com 4 threads: 2475342129
Tempo de execução com OpenMP: 0.043739 segundos

Teste 4 - Tamanho do vetor: 100000000
Soma Paralela com 4 threads: 4949993603
Tempo de execução com OpenMP: 0.082909 segundos

---

# C serial

Teste 1 - Tamanho do vetor: 1000000
Soma Serial: 49533344
Tempo de execução sem OpenMP: 0.003494 segundos

Teste 2 - Tamanho do vetor: 10000000
Soma Serial: 495130367
Tempo de execução sem OpenMP: 0.034799 segundos

Teste 3 - Tamanho do vetor: 50000000
Soma Serial: 2475584720
Tempo de execução sem OpenMP: 0.173520 segundos

Teste 4 - Tamanho do vetor: 100000000
Soma Serial: 4949983022
Tempo de execução sem OpenMP: 0.272823 segundos

---
# Python serial

Executando Teste 1 - Tamanho do vetor: 1000000...
Soma Serial: 49429817
Tempo de execução serial: 0.004228 segundos

Executando Teste 2 - Tamanho do vetor: 10000000...
Soma Serial: 495057014
Tempo de execução serial: 0.033013 segundos

Executando Teste 3 - Tamanho do vetor: 50000000...
Soma Serial: 2475094010
Tempo de execução serial: 0.164423 segundos

Executando Teste 4 - Tamanho do vetor: 100000000...
Soma Serial: 4950201174
Tempo de execução serial: 0.350481 segundos


| Test   |   Vector Size |   CuPy Sum |   CuPy Time (s) |   Python Threads Sum |   Python Threads Time (s) |   CUDA Sum |   CUDA Time (s) |   OpenMP Sum |   OpenMP Time (s) |   C Serial Sum |   C Serial Time (s) |   Python Serial Sum |   Python Serial Time (s) |
|:-------|--------------:|-----------:|----------------:|---------------------:|--------------------------:|-----------:|----------------:|-------------:|------------------:|---------------:|--------------------:|--------------------:|-------------------------:|
| Test 1 |       1000000 |   49479097 |        1.15639  |             49502345 |                  0.014297 |   49504078 |        0.014027 |     49472445 |          0.00195  |       49533344 |            0.003494 |            49429817 |                 0.004228 |
| Test 2 |      10000000 |  494925364 |        0.000118 |            495147563 |                  0.092822 |  495023358 |        0.000392 |    494998960 |          0.010306 |      495130367 |            0.034799 |           495057014 |                 0.033013 |
| Test 3 |      50000000 | 2475298829 |        0.000132 |           2475138719 |                  0.485306 | 2475121780 |        0.001723 |   2475342129 |          0.043739 |     2475584720 |            0.17352  |          2475094010 |                 0.164423 |
| Test 4 |     100000000 | 4949755462 |        9.5e-05  |           4950041011 |                  0.960033 | 4949740356 |        0.004394 |   4949993603 |          0.082909 |     4949983022 |            0.272823 |          4950201174 |                 0.350481 |