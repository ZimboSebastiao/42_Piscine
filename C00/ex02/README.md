**Exercício:** `ft_print_reverse_alphabet.c` 
**Módulo:** `C00`
**Versão da Solução:** `1.0` 
**Área:** `ASCII, Tipos primitivos, Loop`
**Dificuldade:** `Iniciante`  
<br>

---

## 📚 Sumário

* [1. Objetivo e Contexto](#1-objetivo-e-contexto)

  * [Descrição Formal](#descrição-formal)
  * [Relevância](#relevância)

* [2. Abordagem Técnica](#2-abordagem-técnica)

  * [Estratégia Adotada](#estratégia-adotada)
  * [Pseudocódigo](#pseudocódigo)

* [3. Implementação em C](#3-implementação-em-c)

  * [Gráficos de Desempenho (usando tabelas ASCII)](#gráficos-de-desempenho-usando-tabelas-ascii)

* [4. Notas de Revisão](#4-notas-de-revisão)

  * [Revisão Pós-Implementação](#revisão-pós-implementação)
  * [Testes de Diagnóstico](#testes-de-diagnóstico)
  * [Análise Técnica](#análise-técnica)
  * [Aprendizados Consolidados](#aprendizados-consolidados)

* [5. Referências e Leituras Adicionais](#5-referências-e-leituras-adicionais)

---

---


## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que exiba o alfabeto em minúscula, numa única linha, em ordem decrescente, começando pela letra ’z’.

---
### Relevância

Este exercício auxilia na compreensão da manipulação de caracteres ASCII, no uso básico da função write(), e reforça conceitos fundamentais de laços de repetição e controle de fluxo. Diferentemente de abordagens que utilizam incremento, aqui utilizamos decremento para percorrer o alfabeto em ordem inversa.

---
## 2. Abordagem Técnica

### Estratégia Adotada

- **Algoritmo:** algoritmo iterativo de complexidade constante.  
- **Complexidade:** `O(1)` tempo, `O(1)` espaço.  
- **Restrições:** Não utilizar funções de biblioteca além de `write()`.  
--- 
### Pseudocódigo

```kotlin

Início do programa

Função ft_print_reverse_alphabet:
    Inicializar uma variável inteira i com o valor ASCII de 122
    Enquanto i for maior ou igual a 97:
        Escreva o caractere apontado por i
        Decremente i
Fim da função

Função main:
    Chamar ft_print_reverse_alphabet
    Escrever uma quebra de linha
    Retornar 0
Fim da função

Fim do programa


```
---
## 3. Implementação em C

```c
#include <unistd.h>

void	ft_print_reverse_alphabet(void);

int main(void)
{
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	return (0);
}

void	ft_print_reverse_alphabet(void)
{
	int i;

	i = 122;

	while (i >= 97)
	{
		write(1, &i, 1);
		i--;
	}
}


```
#### Saída
```bash
$ zyxwvutsrqponmlkjihgfedcba
```
---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---
## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

O exercício foi implementado com sucesso, imprimindo o alfabeto em ordem decrescente corretamente. A função `ft_print_reverse_alphabet()` utiliza um laço `while` simples e eficiente, controlado pela variável `i` que armazena valores ASCII decrescentes. A restrição de uso exclusiva da syscall `write()` foi respeitada, reforçando o contato direto com chamadas de sistema do Linux. Esta abordagem ajuda a compreender a tradução do código C em operações de baixo nível feitas pelo kernel.

---

### Testes de Diagnóstico

* **Verificação da saída:** Confirmar que o terminal imprime a sequência correta de caracteres `zyxwvutsrqponmlkjihgfedcba`, seguida de uma nova linha.
* **Validação de limites:** Garantir que a condição do laço `while (i >= 97)` funcione corretamente para cobrir todo o alfabeto minúsculo.
* **Testes de robustez:** Embora simples, o código pode ser testado para confirmar que nenhuma função extra (como `printf`) foi usada e que a saída ocorre somente via `write`.
* **Observação de uso de memória:** Verificar, por exemplo via `valgrind` ou ferramentas similares, que não há vazamento de memória (apesar de não ser esperado).

---

### Análise Técnica

* A variável `i` é declarada como `int` e inicializada com o valor ASCII de `'z'` (122). Embora `write()` envie apenas 1 byte por vez, a variável inteira em memória ocupa 4 bytes em arquiteturas modernas. A syscall `write(1, &i, 1)` envia somente o byte menos significativo, que contém o valor do caractere.
* O loop decrescente decremente `i` a cada iteração, imprimindo caracteres de `'z'` a `'a'`.
* O uso da syscall `write()` em vez de funções padrão como `printf()` ou `putchar()` demonstra o controle direto sobre I/O, útil para entender a comunicação entre programa e kernel.
* O código apresenta complexidade `O(1)` tanto em tempo quanto em espaço, pois o número de iterações é fixo (26 caracteres) e não há alocação dinâmica.
* Esta implementação respeita a restrição de não usar bibliotecas adicionais além de `unistd.h`, que provê a syscall `write()`.

---

### Aprendizados Consolidados

1. **Manipulação direta de ASCII:** A compreensão do valor numérico dos caracteres permite manipulação precisa, seja incrementando ou decrementando valores para controle de fluxo.
2. **Chamadas de sistema (syscalls):** O uso do `write()` demonstra como um programa interage diretamente com o sistema operacional para enviar dados ao terminal.
3. **Tipos primitivos e memória:** Mesmo declarando uma variável como `int` (4 bytes), a função `write` pode enviar apenas um byte, enfatizando a importância de entender endianness e estrutura da memória.
4. **Controle de fluxo com loops:** Laços `while` são essenciais para controle iterativo, aqui usados para contar regressivamente em valores ASCII.
5. **Eficiência e simplicidade:** Um algoritmo direto e com baixa complexidade pode resolver problemas comuns de forma clara e eficiente.

---


## 5. Referências e Leituras Adicionais

* Kernighan, Brian W., e Dennis M. Ritchie. *The C Programming Language*. 2ª edição. Prentice Hall, 1988.
* Linux Manual Pages: [write(2) — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
* *ASCII Table and Description*: [ASCII Table](https://www.asciitable.com/)
* GCC Internals: [GCC Documentation](https://gcc.gnu.org/onlinedocs/gccint/)
* *Understanding Linux System Calls* - [Tutorialspoint: Linux System Calls](https://www.tutorialspoint.com/unix_system_calls/write.htm)