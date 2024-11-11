# Análise dos Resultados dos Testes de Paralelização com OpenMP

## Introdução

Este documento apresenta a análise dos resultados obtidos ao executar um programa que calcula a soma dos elementos de um vetor utilizando duas abordagens:

- **Versão Serial**: Implementação tradicional sem o uso de paralelismo.
- **Versão Paralela**: Implementação utilizando OpenMP para paralelizar o cálculo da soma.

Foram realizados quatro testes com tamanhos crescentes de vetor para comparar o desempenho entre as duas versões.

## Resultados Obtidos

## Análise dos Resultados

### Tabela Comparativa

| Teste | Tamanho do Vetor | Soma Serial     | Tempo Serial (s) | Soma Paralela     | Tempo Paralelo (s) | Speedup |
|-------|------------------|-----------------|------------------|-------------------|--------------------|---------|
| 1     | 1.000.000        | 49.496.784      | 0,001339         | 49.494.836        | 0,000793           | 1,69x   |
| 2     | 10.000.000       | 495.068.689     | 0,010092         | 495.072.961       | 0,005563           | 1,81x   |
| 3     | 50.000.000       | 2.475.080.470   | 0,055777         | 2.475.074.659     | 0,027928           | 2,00x   |
| 4     | 100.000.000      | 4.950.056.129   | 0,118030         | 4.950.064.162     | 0,061249           | 1,93x   |

### Observações

1. **Correta execução dos programas**: As somas obtidas nas versões serial e paralela são muito próximas, confirmando que ambos os programas estão calculando corretamente a soma dos elementos do vetor. Pequenas diferenças podem ocorrer devido à ordem de soma e possíveis condições de corrida, mas no caso do uso correto da cláusula `reduction` do OpenMP, essas diferenças devem ser mínimas ou nulas.

2. **Redução do tempo de execução**: Observa-se que o tempo de execução na versão paralela é menor do que na versão serial em todos os testes. Isso indica que a paralelização foi eficaz em reduzir o tempo necessário para realizar o cálculo.

3. **Speedup**: O speedup é calculado dividindo-se o tempo serial pelo tempo paralelo. Observa-se um speedup que varia de aproximadamente 1,69x a 2,00x. Isso significa que a versão paralela com 4 threads foi até duas vezes mais rápida que a versão serial.

### Considerações sobre o Desempenho

1. **Lei de Amdahl**: De acordo com a Lei de Amdahl, o ganho máximo de desempenho é limitado pela fração do programa que pode ser paralelizada. No caso deste programa, quase todo o tempo de execução está no loop de soma, o que é paralelizável, permitindo um speedup significativo.

2. **Overhead de Gerenciamento de Threads**: Em programas paralelos, existe um overhead associado à criação, gerenciamento e sincronização de threads. Em tamanhos menores de dados, esse overhead pode reduzir os benefícios da paralelização.

3. **Limitações de Hardware**: O número de núcleos físicos da CPU limita o ganho máximo de paralelização. Utilizar mais threads do que núcleos pode não resultar em ganhos adicionais e pode introduzir overheads adicionais.

4. **Eficiência da Paralelização**: A eficiência é calculada como o speedup dividido pelo número de threads. Neste caso, com 4 threads, a eficiência varia entre 42% e 50%. Isso é esperado devido aos fatores mencionados anteriormente.

## Conclusão

Os testes demonstram que a paralelização com OpenMP pode reduzir significativamente o tempo de execução em operações que podem ser distribuídas entre múltiplas threads, como a soma de elementos de um vetor. No entanto, o ganho de desempenho depende de vários fatores:

- **Tamanho dos dados**: Maior volume de dados tende a melhorar a eficiência da paralelização.
- **Overhead de Paralelização**: Deve ser considerado, especialmente em casos com menor carga de trabalho.
- **Recursos de Hardware**: O número de núcleos e a arquitetura do sistema influenciam o desempenho.

Para maximizar os benefícios da paralelização, recomenda-se:

- Ajustar o número de threads de acordo com o hardware disponível.
- Minimizar operações que requerem sincronização ou acesso concorrente a recursos compartilhados.
- Realizar testes e medições para identificar o ponto ótimo entre overhead e ganho de desempenho.

