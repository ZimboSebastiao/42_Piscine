**Exercício:** ft_ultimate_ft.c 
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Ponteiros e Memória `
**Dificuldade:** `Iniciante`
<br>

---

## 📚 Sumário

1. [Objetivo e Contexto](#1-objetivo-e-contexto)  
2. [Abordagem Técnica](#2-abordagem-técnica)  
3. [Implementação em C](#3-implementação-em-c)  
4. [Notas de Revisão](#4-notas-de-revisão)  
5. [Referências e Leituras Adicionais](#5-referências-e-leituras-adicionais) 

---


## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que tenha um ponteiro para ponteiro para ponteiro para pon-
teiro para ponteiro para ponteiro para ponteiro para ponteiro para ponteiro para
int em parâmetro e dê ao int o valor de 42.

---

### Relevância

Este exercício busca testar a capacidade de compreender e manipular ponteiros múltiplos, um conceito essencial para entender a modelagem de memória em C. Ainda que tal nível de indireção seja raro em aplicações reais, ele treina a habilidade de navegar pela complexidade de camadas de abstração algo comum ao manipular estruturas mais avançadas como matrizes multidimensionais, estruturas aninhadas e ponteiros a funções.

---

## 2. Abordagem Técnica

### Estratégia Adotada

A função recebe como argumento um ponteiro de nove níveis de indireção (`int *********nbr`). A estratégia é acessar o valor original através das nove desreferenciações e atribuir o valor `42`.

- **Algoritmo:**  
  Atribuição direta via desreferenciação múltipla.
- **Complexidade:**  
  - Tempo: O(1) — é uma única operação de atribuição.  
  - Espaço: O(1) — nenhuma alocação adicional é feita.
- **Restrições:**  
  - Não utilizar nenhuma bibliotecas.

---

### Pseudocódigo

```bash
função ft_ultimate_ft(recebe ptr para ptr para ... para int)
    atribua 42 ao valor acessado através das 9 desreferenciações
fim

```
---
## 3. Implementação em C

```c

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int main()
{
	int a = 0;
	int *ptr1= &a;
	int **ptr2 = &ptr1;
	int ***ptr3 = &ptr2;
	int ****ptr4 = &ptr3;
	int *****ptr5 = &ptr4;
	int ******ptr6 = &ptr5;
	int *******ptr7 = &ptr6;
	int ********ptr8 = &ptr7;
	int *********ptr9 = &ptr8;

	ft_ultimate_ft(ptr9);
	printf("%d\n", *********ptr9);
	return (0);
}

void	ft_ultimate_ft(int *********nbr)
{
	int number;
	number = 42;

	*********nbr = number;
	
	
}

```

#### Saída esperada
```bash
42
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

- A função cumpre seu propósito com clareza e simplicidade.
- Apesar da complexidade aparente, não há necessidade de iteração ou lógica condicional.
- A principal armadilha está na compreensão do número de níveis de indireção. 

---


## 5. Referências e Leituras Adicionais

* \[The C Programming Language – Brian W. Kernighan & Dennis M. Ritchie]
* [Pointers in C – Tutorialspoint](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)
* [Ponteiros em C - Curso em Vídeo (YouTube)](https://www.youtube.com/watch?v=w5D6HHSit4U)
* [Understanding C Pointers – Stack Overflow Thread](https://stackoverflow.com/questions/5527666/what-are-the-differences-between-a-pointer-variable-and-a-pointer-in-c)
* [Diagrama de Ponteiros - Draw.io Models](https://app.diagrams.net)


