**Exercício:** ft_rev_int_tab.c 
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Manipulação de Arrays e Ponteiros`
**Dificuldade:** `Iniciante`
<br>

---

## 📚 Sumário

1. [Objetivo e Contexto](#1-objetivo-e-contexto)  
2. [Abordagem Técnica](#2-abordagem-técnica)  
3. [Implementação em C](#3-implementação-em-c)   
6. [Referências e Leituras Adicionais](#5-referências-e-leituras-adicionais) 

---


## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que inverta um array de inteiros (o primeiro item vai por
último, o segundo vai na penúltima posição, e assim por diante).  
A função recebe dois parâmetros:
- Um ponteiro `int *tab` apontando para o início do array.
- Um inteiro `size` representando o número de elementos no array.

---

### Relevância

Este exercício serve como introdução à manipulação de arrays e ponteiros, além de reforçar os conceitos de indexação, iteração com controle de limites e trocas de valores com uso de variáveis temporárias. Trata-se de um passo fundamental para o entendimento de estruturas de dados e algoritmos básicos.


## 2. Abordagem Técnica

### Estratégia Adotada


A solução utiliza a técnica de dois ponteiros:
1. Um ponteiro começa no início do array
2. Outro ponteiro começa no final
3. Os elementos são trocados iterativamente
4. Os ponteiros se movem em direção ao centro até se cruzarem

- **Algoritmo:** Inversão in-place usando dois índices  
- **Complexidade:**  
  - Tempo: O(n/2) → O(n) linear  
  - Espaço: O(1) constante (apenas 3 variáveis temporárias) 
- **Restrições:**  
  - Não utilizar nenhuma biblioteca.

--- 
### Pseudocódigo

```bash

PROCEDIMENTO reverse_array(tab, size)
    i ← 0
    j ← size - 1
    
    ENQUANTO i < j FAÇA
        temp ← tab[i]
        tab[i] ← tab[j]
        tab[j] ← temp
        i ← i + 1
        j ← j - 1
    FIM ENQUANTO
FIM PROCEDIMENTO

```
---
## 3. Implementação em C

```c

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int main()
{
	
	int i = 0;
	int size = 7;
	int tab[] = {1, 2, 3, 4, 5, 6, 7};
	
	ft_rev_int_tab(tab, size);
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;

	}

	
	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{

	int i;
	int j;
	int temp;

	i = 0;
	j = size - 1;

	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;

		i++;
		j--;
	}
}

```

#### Saída esperada
```bash
7654321

```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Referências e Leituras Adicionais

* [C Programming - Arrays (GeeksForGeeks)](https://www.geeksforgeeks.org/arrays-in-c-cpp/)
* [Computerphile - Arrays e Pointers](https://www.youtube.com/watch?v=DTxHyVn0ODg)
* *The C Programming Language*, Brian W. Kernighan e Dennis M. Ritchie – Capítulo sobre Arrays e Funções
* [Wikipedia: In-place algorithm](https://en.wikipedia.org/wiki/In-place_algorithm)


