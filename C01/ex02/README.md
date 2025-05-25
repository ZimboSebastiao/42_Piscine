**Exercício:** ft_swap.c
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Ponteiros, Manipulação de Memória`
**Dificuldade:** `Iniciante`
<br>

---

## 📚 Sumário

1. [Objetivo e Contexto](#1-objetivo-e-contexto)  
2. [Abordagem Técnica](#2-abordagem-técnica)  
3. [Implementação em C](#3-implementação-em-c)  
4. [Referências e Leituras Adicionais](#5-referências-e-leituras-adicionais) 

---


## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que troque o conteúdo de dois inteiros cujos endereços são
dados como parâmetros.

---

### Relevância

Este exercício introduz o conceito essencial de **ponteiros** em C um dos pilares da linguagem. Compreender como manipular dados via seus endereços é fundamental para trabalhar com arrays, strings, alocação dinâmica e estruturas mais complexas, como listas ligadas.

### Importância Matemática

Embora o exercício seja de natureza computacional, ele ensina um conceito matemático importante: **inversão de valores**. Além disso, relaciona-se com a lógica de trocas em algoritmos de ordenação como bubble sort, insertion sort, entre outros.

## 2. Abordagem Técnica

### Estratégia Adotada


A função `ft_swap` utiliza uma variável auxiliar (`temp`) para armazenar temporariamente o valor de um dos inteiros, permitindo a troca entre os dois.

- **Algoritmo:**  
  1. Armazena `*a` em `temp`.  
  2. Atribui o valor de `*b` em `*a`.  
  3. Atribui `temp` em `*b`.  

- **Complexidade:**  
  - Tempo: O(1) — A operação de troca ocorre em tempo constante.  
  - Espaço: O(1) — Uma única variável auxiliar é usada.  
- **Restrições:**  
  - Não utilizar nenhuma biblioteca.

--- 

### Pseudocódigo

```bash
função ft_swap(recebe endereços de dois inteiros: a e b)
    definir temp como inteiro
    temp = valor apontado por a
    valor apontado por a = valor apontado por b
    valor apontado por b = temp
fim

```
---
## 3. Implementação em C

```c

#include <stdio.h>

void	ft_swap(int *a, int *b);

int main()
{
	int a = 2;
	int b = 4;
	ft_swap(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}


```

#### Saída esperada
```bash
a = 4
b = 2

```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |




---


## 4. Referências e Leituras Adicionais


* [Documentação Oficial da Linguagem C (ISO C Standard)](https://en.cppreference.com/w/c)
* KERNIGHAN, Brian W.; RITCHIE, Dennis M. *The C Programming Language*.
* 42 Docs: [Ponteiros em C](https://github.com/42School)
* Artigo: [Entendendo Ponteiros em C - por André Backes](https://www.embarcados.com.br/ponteiros-linguagem-c/)
* Exercício relacionado: `ft_ultimate_swap` (para treinar manipulação direta entre ponteiros sem variável auxiliar)

