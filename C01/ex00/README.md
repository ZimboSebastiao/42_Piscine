**Exercício:** ft_ft.c 
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
4. [Referências e Leituras Adicionais](#4-referências-e-leituras-adicionais) 

---


## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que tenha um ponteiro para int em parâmetro e dê ao int o
valor de 42.

---

### Relevância

Este exercício serve como introdução ao conceito de **ponteiros** em C uma das bases mais importantes da linguagem. Compreender ponteiros é essencial para:

- Manipular memória de forma explícita;
- Compreender a passagem de parâmetros por referência;
- Trabalhar com arrays, strings e estruturas dinâmicas.


## 2. Abordagem Técnica

### Estratégia Adotada

- **Objetivo:** Atribuir o valor 42 ao inteiro apontado.
- **Técnica:** Passagem de argumento por referência (ponteiro).
- **Segurança:** Garantir que o ponteiro não seja **NULL** em contextos mais avançados (não exigido neste exercício simples).

- **Algoritmo:** 
1. Acessar a variável referenciada por `*nbr`;
2. Atribuir o valor `42`.
- **Complexidade:**  
  - Tempo: O(1) 
  - Espaço: O(1)
- **Restrições:**  
  - Não utilizar nenhuma bibliotecas além.

--- 
### Pseudocódigo

```bash
função ft_ft(recebe ponteiro para inteiro):
    atribuir 42 à variável apontada

```
---
## 3. Implementação em C

```c

#include <stdio.h>

void	ft_ft(int *nbr);

int	main()
{

	int number;

	ft_ft(number);
	
	printf("%d\n", *number);
 return (0);
}

void	ft_ft(int *nbr)
{
	int number = 42;

	*nbr = number;
	

}

```

#### Explicação

- `ft_ft` recebe um ponteiro `int *nbr`.
- `*nbr = 42;` modifica diretamente o valor da variável para onde `nbr` aponta.
- Em `main`, passamos o **endereço** da variável `number` usando `&number`.

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



## 4. Referências e Leituras Adicionais

* [Manual GNU C: Pointers](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Pointers)
* \[The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie]
* [Curso C Progressivo: Ponteiros](https://www.cprogressivo.net/2012/10/ponteiros-em-C.html)
* [Valgrind para análise de memória](https://valgrind.org/)

