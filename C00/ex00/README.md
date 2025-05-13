**Exercício:** `ft_putchar.c` 
**Módulo:** `C00`
**Versão da Solução:** `1.0` 
**Área:** `ASCII, tipos primitivos, char`
**Dificuldade:** `Iniciante`  
<br>

---
## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que exiba o caractere passado como parâmetro.

---
### Relevância

Criar sua própria versão da função **putchar** em C é um exercício fundamental que carrega uma série de aprendizados estruturantes para quem deseja dominar a programação de baixo nível com solidez.

Ao implementar essa função, você é exposto diretamente à manipulação de memória atráves de ponteiros. compreendendo como os dados são representados fisicamente na RAM em especial, como um caractere é convertido para sua forma binária e armazenado em um único byte. 

Você também interage com o sistema operacional por meio de uma chamada de sistema (write), entendendo que imprimir algo na tela não é apenas uma abstração, mas uma operação real envolvendo comunicação entre o programa e o kernel, que escreve esse dado em um recurso controlado pelo sistema, identificado por um descritor de arquivo.

Essa experiência te ensina como a saída padrão (stdout) funciona, reforçando o conceito Unix de que "tudo é arquivo" e mostrando que o terminal é apenas mais um recurso acessado como um arquivo via descritor. Ao construir manualmente uma função que reproduz o comportamento de uma função padrão da linguagem, você também aprebde a não depender cegamente das bibliotecas prontas, sendo capaz de entender e eventualmente reimplementar partes fundamentais da linguagem e do sistema.

Em essência, reescrever putchar é mais do que reinventar a roda, é descobrir como a roda gira, como ela é fixada no eixo e como o movimento é transmitido, tudo isso em apenas uma linha de saída.

---
## 2. Abordagem Técnica

### Estratégia Adotada

- **Algoritmo:** acesso explícito ao nível do sistema `write(syscall)`.  
- **Complexidade:** `O(1)` tempo, `O(1)` espaço.  
- **Restrições:** Não utilizar funções de biblioteca além de `write()`.  
--- 
### Pseudocódigo

1. Incluir a biblioteca `unistd.h`. 
2. Definir a função `ft_putchar`, do tipo void, que recebe um parâmetro do tipo char.  
3. Dentro da função, usar `write` para enviar `1 byte` do endereço do caractere para o descritor de saída padrão.  
4. No `main`, chamar `ft_putchar` passando um caractere.
---
## 3. Implementação em C

```c
#include <unistd.h>

void	ft_putchar(char c);

int main()
{
	ft_putchar(79);
	write(1, "\n", 1);
	return (0);
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

```

---
### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---
## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

- Foi usada a syscall `write` com o file descriptor 1, que representa a **saída padrão (stdout)**. 
- Passamos o endereço da variável c `&c` e indicoi que 1 byte seria escrito, que representa um caractere.
- O valor `79` foi passado como parâmetro, que corresponde ao caractere **'O'** na tabela ASCII.
- O valor foi armazenado na stack, e a função `write` usou esse endereço para imprimir o conteúdo no terminal.
- O compilador não converte o número para caractere, apenas interpreta o valor conforme o tipo. Quem mostra o caractere no terminal é o terminal, com base na codificação ASCII do byte recebido.
- A função foi testada com sucesso no terminal e imprimiu **O**.

---

### Testes de Diagnóstico

- Foi utilizado o `valgrind --tool=massif` para medir uso de memória.
- O comando gerou um gráfico ASCII via `ms_print`.
- O gráfico mostrou 0 B alocados indicando nenhum uso de heap (correto, já que não há `malloc`).
- O topo da escala do gráfico `(1^ B)` representa 1 byte como valor de referência mesmo sem uso de memória.
- O programa foi analisado por um grafo de chamadas (callgraph).
- O grafo mostrou que `main` chama `ft_putchar`, que chama `write`, numa cadeia lógica e limpa.

---

### Análise Técnica

- O algoritmo é de complexidade constante: `O(1)` em tempo e espaço.
- Não houve loops, recursões nem estruturas complexas.
- A stack foi usada corretamente e eficientemente.
- Nenhuma alocação dinâmica foi feita (heap não utilizado).
- O programa terminou rapidamente e com consumo mínimo de recursos.

---

### Aprendizados Consolidados

- Entendimento de como a função `write` funciona e se comunica com o kernel.
- Compreensão prática da tabela ASCII e como valores são convertidos para caracteres visíveis.
- Experiência real com ferramentas de análise profissional de desempenho (como `valgrind`, `ms_print`, `callgraph`).
- Noção de como o sistema operacional trata bytes e file descriptors.
- Reconhecimento de que `ft_putchar` é uma abstração útil para simplificar chamadas de sistema em C.

---

## 5. Referências e Leituras Adicionais

[Geeksforgeeks - putchar() function in C](https://www.geeksforgeeks.org/putchar-function-in-c/).

[W3School - Função C stdio putchar()](https://www-w3schools-com.translate.goog/c/ref_stdio_putchar.php?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc)