**Exercício:** ft_div_mod.c 
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Aritmética Inteira, Manipulação de Ponteiros `
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

Escreva uma função ft_div_mod que tenha a seguinte prototipagem:
```c
void ft_div_mod(int a, int b, int *div, int *mod);
```

Essa função deve calcular:
- a divisão inteira de `a por b`, armazenando o resultado no endereço apontado por `div`
- o resto da divisão de `a por b`, armazenando no endereço apontado por `mod`.

---

### Relevância

Este exercício introduz dois conceitos essenciais em C:
- **Manipulação de ponteiros:** passar endereços de memória como argumentos de função.
- **Funções com múltiplos resultados:** uma técnica comum em C quando se deseja retornar mais de um valor.

Além disso, treina a compreensão sobre como a aritmética inteira se comporta em divisões e como acessar e modificar valores através de ponteiros.

### Importância Matemática

Divisão inteira e resto (módulo) são operações fundamentais em matemática discreta e teoria dos números. São amplamente utilizadas em algoritmos de criptografia, estruturas de dados baseadas em hashing, e problemas clássicos como o algoritmo de Euclides (MDC).


## 2. Abordagem Técnica

### Estratégia Adotada

* Receber os valores `a` e `b` por valor.
* Utilizar operadores aritméticos `/` (divisão inteira) e `%` (módulo).
* Utilizar os ponteiros `*div` e `*mod` para armazenar os resultados.

---

* **Algoritmo:**

  * Aplicar a fórmula `*div = a / b`
  * Aplicar a fórmula `*mod = a % b`

* **Complexidade:**

  * Tempo: O(1)
  * Espaço: O(1)

- **Restrições:**  
  - Não utilizar nenhuma biblioteca.
--- 
### Pseudocódigo

```bash
função ft_div_mod(a, b, *div, *mod):
    se b for diferente de 0:
        *div ← a dividido por b
        *mod ← a módulo b

```
---
## 3. Implementação em C

```c

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main()
{

	int	*div, *mod;

	ft_div_mod(10, 3, div, mod);
	printf("Divisão: %d\n Resto: %d\n", *div, *mod);
	return (0);
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = (a / b);
	*mod = (a % b);
}

```

#### Saída esperada
```bash
Divisão: 3
Resto: 1
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---



## 4. Referências e Leituras Adicionais

* 📘 [Manual do Operador Módulo (%) em C – GeeksforGeeks](https://www.geeksforgeeks.org/modulus-operator-in-c-cpp/)
* 📘 [Ponteiros em C – Curso Harvard CS50 (pt-BR traduzido)](https://cs50.harvard.edu/x/2023/notes/4/)
* 📘 \[The C Programming Language – Kernighan & Ritchie, Capítulo 5]



