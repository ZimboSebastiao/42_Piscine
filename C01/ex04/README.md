**Exercício:** ft_ultimate_div_mod.c 
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Operações Aritméticas e Manipulação de Ponteiros`
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

Escreva uma função ft_ultimate_div_mod que tenha a seguinte prototipagem:

```bash
void ft_ultimate_div_mod(int *a, int *b);
```

Essa função divide os int apontados por a e b. O resultado da divisão está ar-
mazenado no int apontado por a. O resultado do resto da divisão está armazenado
no int apontado por b.

---

### Relevância

Esse exercício serve como introdução à manipulação de ponteiros e ao conceito de passagem por referência. É essencial para entender como modificar valores diretamente na memória e como funções podem interagir com variáveis externas ao seu escopo.

### Importância Matemática

O conceito de divisão inteira e operação módulo é amplamente utilizado em matemática discreta, algoritmos de criptografia, programação de baixo nível, e controle de fluxo em estruturas de repetição e particionamento de dados. Compreender como extrair quociente e resto é fundamental para problemas clássicos como:

- Conversão de bases numéricas;
- Detecção de números pares/ímpares;
- Estruturação de laços condicionais e algoritmos recursivos.

## 2. Abordagem Técnica

### Estratégia Adotada

A abordagem consiste em:

1. Salvar os valores apontados por `a` e `b` em variáveis temporárias para evitar perda de dados;
2. Realizar a divisão inteira `a / b` e armazenar o resultado no local apontado por `a`;
3. Calcular o módulo `a % b` e armazenar o resultado no local apontado por `b`.

---

* **Algoritmo:**

  * A função realiza apenas duas operações aritméticas e duas atribuições.

* **Complexidade:**

  * Tempo: O(1)
  * Espaço: O(1)
- **Restrições:**  
  - Não utilizar nenhuma biblioteca.

--- 

### Pseudocódigo

```bash
função ft_ultimate_div_mod(ponteiro a, ponteiro b):
    armazenar valor de *a em temp_a
    armazenar valor de *b em temp_b
    *a recebe temp_a dividido por temp_b
    *b recebe temp_a módulo temp_b

```
---
## 3. Implementação em C

```c

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int a = 10;
	int b = 6;
	
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	int d;

	c = *a;
	d = *b;

	*a = (c / d);
	*b = (c % d);
}

```

#### Saída esperada
```bash
a = 1
b = 4
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Referências e Leituras Adicionais

* [Documentação oficial do operador módulo (%) em C](https://en.cppreference.com/w/c/language/operator_arithmetic)
* [GeeksforGeeks - Pointers in C](https://www.geeksforgeeks.org/pointers-in-c-and-c-set-1-introduction-arithmetic-and-array/)
* [CS50 Harvard - Week 1: C (Pointers e Arithmetic)](https://cs50.harvard.edu/x/2024/weeks/1/)
* K\&R, "The C Programming Language" – Seções sobre funções e ponteiros



