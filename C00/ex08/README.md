**Exercício:** ft_print_combn.c
**Módulo:** C00
**Versão da Solução:** 1.0 
**Área:** `Lógica/Recursão e Combinação de Valores`
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

Escreva uma função que exiba todas as diferentes combinações de n números em
ordem crescente.

- n será tal que: 0 < n <10.
- Se n = 2, isso resulta em algo do tipo:

```bash 
01, 02, 03, ..., 09, 12, ..., 79, 89
```

---

### Relevância

Este exercício introduz conceitos fundamentais para combinações, recursividade, manipulação de arrays e controle de fluxos lógicos. Dominar isso é essencial para problemas de algoritmos e busca.

### Importância Matemática

Este exercício está profundamente enraizado no conceito matemático de combinações sem repetição. No caso de **n**, estamos gerando subconjuntos de tamanho **n** do conjunto ``{0, 1, ..., 9}`, onde a ordem importa apenas para manter a ordenação crescente.


## 2. Abordagem Técnica

### Estratégia Adotada

- Utilização de um array de inteiros que representa a combinação atual.

- Impressão da combinação atual com **write**.

- Verificação do fim com base no valor do primeiro elemento.

- Incremento controlado do array para obter a próxima combinação válida.


- **Algoritmo:** 
	- Inicializar o array com `{0, 1, ..., n-1}`.

	- Imprimir.

	- Atualizar para a próxima combinação.

	- Repetir até o valor de `comb[0]` atingir `10 - n`.
- **Complexidade:**  
  - Tempo: O(n) 
  - Espaço: O(n)
- **Restrições:**  
  - Não utilizar bibliotecas além de `unistd.h`  
  - Somente a função `write` é permitida para saída  
--- 
### Pseudocódigo

```bash

func ft_print_combn(n):
    inicializa comb[] com valores de 0 até n-1
    enquanto true:
        imprime os elementos de comb
        se comb[0] == 10 - n:
            break
        imprime ", "
        i = n - 1
        enquanto comb[i] == 9 - (n - 1 - i):
            i--
        comb[i]++
        para j de i+1 até n:
            comb[j] = comb[j-1] + 1

```
---
## 3. Implementação em C

```c

#include <unistd.h>

void	ft_print_combn(int n);



int main()
{
	ft_print_combn(9);
	return (0);
}

void	ft_print_combn(int n)
{
	int comb[10];
	int i;

	if (n < 1 || n > 9)
		return;

	// Inicializa a combinação com os menores dígitos
	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}

	while (1)
	{
		// Escreve os dígitos atuais
		i = 0;
		while (i < n)
		{
			char c = comb[i] + '0';
			write(1, &c, 1);
			i++;
		}

		// Verifica se é a última combinação
		if (comb[0] == 10 - n)
			break;

		write(1, ", ", 2);

		// Incrementa a combinação
		i = n - 1;
		while (i >= 0 && comb[i] == 9 - (n - 1 - i))
			i--;

		comb[i]++;
		while (++i < n)
			comb[i] = comb[i - 1] + 1;
	}
}



```

#### Saída esperada (n = 2)
```bash
01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, ..., 89
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

- Uso inteligente de arrays para representação de combinações.

-- A impressão é feita manualmente com write, reforçando o controle de baixo nível.

- O incremento do array simula o comportamento de uma contagem combinatória.

---


## 5. Referências e Leituras Adicionais

* [Man page do `write`](https://man7.org/linux/man-pages/man2/write.2.html)
* [Combinatória - Khan Academy](https://pt.khanacademy.org/math/statistics-probability/probability-library)
* [Valgrind Massif](http://valgrind.org/docs/manual/ms-manual.html)
* [Stack vs Heap - GeeksforGeeks](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)

