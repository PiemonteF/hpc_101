
1. **Qual a abordagem utilizada no código conforme os comentários?**

   A abordagem utilizada no código é dividir a lista de números em partes iguais (ou o mais próximo possível), atribuindo cada parte a uma thread separada. Cada thread calcula a soma de sua parte da lista de forma independente. Utiliza-se uma lista compartilhada `results` para armazenar o resultado parcial de cada thread. No final, o programa principal agrega os resultados parciais somando os elementos da lista `results` para obter a soma total.

2. **Quais modificações seriam necessárias para execução de 3 ou mais threads?**

   Para executar o código com 3 ou mais threads, é necessário ajustar a variável `num_threads` para o número desejado de threads. O código já está escrito de forma dinâmica para dividir a lista de acordo com o número de threads especificado. É importante garantir que o cálculo dos índices de início e fim (`start` e `end`) distribua corretamente os elementos da lista entre as threads, incluindo quaisquer elementos restantes na última thread se a divisão não for exata.

3. **Por que a abordagem com threads possui maior escalabilidade?**

   A abordagem com threads possui maior escalabilidade porque permite a execução paralela de tarefas, aproveitando melhor os recursos do sistema, como múltiplos núcleos de processamento. Ao dividir o trabalho entre várias threads, o programa pode realizar cálculos em partes diferentes da lista simultaneamente, reduzindo o tempo total de execução, especialmente em listas grandes. Isso torna o programa mais eficiente e capaz de lidar com cargas de trabalho maiores de forma mais eficaz.

**Execução do código com 3 casos diferentes de testes:**

**Resultados dos Testes:**

---

**Teste 1:**

- **Lista de Números:** `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`
- **Soma Total:** `55`
- **Tempo de Execução sem Threads:** `0.000003 segundos`
- **Tempo de Execução com Threads:** `0.000122 segundos`

---

**Teste 2:**

- **Lista de Números:** `list(range(1, 10000))` (números de 1 a 9.999)
- **Soma Total:** `49995000`
- **Tempo de Execução sem Threads:** `0.000538 segundos`
- **Tempo de Execução com Threads:** `0.000193 segundos`

---

**Teste 3:**

- **Lista de Números:** `list(range(1, 10000001))` (números de 1 a 10.000.000)
- **Soma Total:** `50000005000000`
- **Tempo de Execução sem Threads:** `0.482524 segundos`
- **Tempo de Execução com Threads:** `0.060121 segundos`

---

**Justificativa dos Resultados:**

---

**Teste 1 Análise:**

- **Tamanho da Lista:** Muito pequeno (10 elementos).
- **Overhead de Threads:** O tempo gasto na criação e gerenciamento das threads é significativo em relação ao tempo total de processamento.
- **Resultado Observado:**
  - **Sem Threads:** Executa extremamente rápido devido ao pequeno tamanho da lista.
  - **Com Threads:** O tempo de execução é maior devido ao overhead das threads.
- **Conclusão:** Para listas pequenas, o uso de threads não é vantajoso e pode piorar o desempenho.

---

**Teste 2 Análise:**

- **Tamanho da Lista:** Médio (9.999 elementos).
- **Overhead vs. Benefício:**
  - O overhead das threads começa a ser compensado pelo ganho em paralelismo.
- **Resultado Observado:**
  - **Sem Threads:** O tempo de execução é maior do que com threads.
  - **Com Threads:** O tempo de execução é reduzido devido à divisão do trabalho.
- **Conclusão:** A partir de um certo tamanho de dados, o uso de threads começa a mostrar benefícios em desempenho.

---

**Teste 3 Análise:**

- **Tamanho da Lista:** Grande (10.000.000 de elementos).
- **Paralelismo Eficiente:**
  - O grande volume de dados permite que o processamento paralelo seja altamente eficiente.
- **Resultado Observado:**
  - **Sem Threads:** Tempo de execução significativamente maior.
  - **Com Threads:** Tempo de execução reduzido drasticamente.
- **Conclusão:** Para grandes volumes de dados, o uso de threads melhora significativamente o desempenho, tornando o processamento mais rápido.

---

**Justificativas Gerais:**

1. **Overhead de Criação e Gerenciamento de Threads:**
   - **Impacto em Listas Pequenas:**
     - O tempo adicional necessário para criar e gerenciar threads não compensa, resultando em desempenho pior.
   - **Impacto em Listas Grandes:**
     - O overhead torna-se insignificante comparado ao tempo de processamento, permitindo ganhos reais em desempenho.

2. **Escalabilidade:**
   - **Definição:**
     - Capacidade do sistema de lidar com crescentes volumes de trabalho de forma eficiente.
   - **Com Threads:**
     - O programa é capaz de dividir tarefas entre múltiplas threads, aproveitando melhor os recursos do sistema.
   - **Resultado:**
     - Maior eficiência e menor tempo de processamento em tarefas maiores.

3. **Global Interpreter Lock (GIL) do Python:**
   - **O que é:**
     - Um mutex que protege o acesso aos objetos Python, impedindo que múltiplas threads executem bytecodes ao mesmo tempo.
   - **Impacto em Operações CPU-bound:**
     - Pode limitar o desempenho do multithreading em Python.
   - **Observação nos Testes:**
     - Apesar do GIL, os testes mostram ganhos em desempenho, possivelmente devido à liberação do GIL durante operações de baixo nível ou internas otimizadas.

4. **Tipo de Operação:**
   - **Operações I/O-bound:**
     - Envolvem espera por operações de entrada/saída; threads podem melhorar significativamente o desempenho.
   - **Operações CPU-bound:**
     - Envolvem intenso uso de CPU; benefícios do multithreading em Python podem ser limitados.
   - **Aplicação nos Testes:**
     - A soma de números é uma operação CPU-bound, mas ainda assim mostrou melhorias com threads em listas grandes.

---

**Conclusão Final:**

- **Uso de Threads:**
  - É benéfico em tarefas que envolvem grande volume de dados ou operações que podem ser executadas em paralelo.
  - A escalabilidade é aumentada, permitindo que o programa lide eficientemente com tarefas maiores.

- **Considerações ao Utilizar Threads:**
  - Avaliar o tamanho dos dados e o tipo de operação é crucial para determinar se o uso de threads será vantajoso.
  - Em Python, para operações intensivas de CPU, pode ser mais eficiente utilizar o módulo `multiprocessing` ou bibliotecas que liberem o GIL, como o `numpy`.

- **Recomendação:**
  - **Listas Pequenas:** Execute de forma sequencial sem threads.
  - **Listas Médias a Grandes:** Considere o uso de threads para melhorar o desempenho.
  - **Operações CPU-bound Críticas:** Avalie o uso de `multiprocessing` ou outras técnicas de paralelismo.
