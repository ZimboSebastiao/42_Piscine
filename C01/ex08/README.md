**Exercício:** ft_sort_int_tab.c  
**Módulo:** C01  
**Versão da Solução:** 1.0  
**Área:** `Algoritmos de Ordenação`  
**Dificuldade:** `Iniciante`  
<br>  

---  

## 📚 Sumário  

1. [Objetivo e Contexto](#1-objetivo-e-contexto)  
2. [Abordagem Técnica](#2-abordagem-técnica)  
3. [Implementação em C](#3-implementação-em-c)  
4. [Análise de Complexidade](#4-análise-de-complexidade)  
5. [Notas de Revisão](#5-notas-de-revisão)  
6. [Referências e Leituras Adicionais](#6-referências-e-leituras-adicionais)  

---  

## 1. Objetivo e Contexto  

### Descrição Formal  
Escreva uma função que ordene um array de inteiros em ordem crescente, utilizando apenas operações de comparação e troca.  
- **Parâmetros:**  
  - `int *tab`: Ponteiro para o primeiro elemento do array.  
  - `int size`: Número de elementos no array.  
- **Restrições:**  
  - Não utilizar funções de bibliotecas externas.  

### Relevância  
- Introduz conceitos fundamentais de algoritmos de ordenação.  
- Prática essencial para entender complexidade algorítmica e manipulação de arrays em C.  

### Importância Matemática  
- Demonstra a aplicação do **Bubble Sort**, um algoritmo de ordenação quadrático (`O(n²)`).  
- Base para entender algoritmos mais eficientes como *Quick Sort* e *Merge Sort*.  

---  

## 2. Abordagem Técnica  

### Estratégia Adotada  
- **Algoritmo:** Bubble Sort.  
- **Complexidade:**  
  - Tempo: `O(n²)` no pior caso.  
  - Espaço: `O(1)` (ordenação in-place).  
- **Restrições:**  
  - Não alocar memória adicional.  

### Pseudocódigo  
```bash
PARA i DE 0 ATÉ size-2 FAÇA  
    PARA j DE 0 ATÉ size-i-2 FAÇA  
        SE tab[j] > tab[j+1] ENTÃO  
           TROCA(tab[j], tab[j+1]) 

``` 

---

## 3. Implementação em C

```c

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main()
{
	int i = 0;
	int	size = 9;
	int array[] = {3,1,2,8,9,5,6,7,0};
	ft_sort_int_tab(array, size);

	while(i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	temp = 0;
	
	while(i < size - 1)
	{
		j  = 0;
		while (j < size - i - 1)
		{
			if(tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}

}

```

#### Saída esperada
```bash
0  
1  
2  
3  
5  
6  
7  
8  
9  
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot  | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes)     |
| --------- | --------- | ------------- | ----------------- | ------------------ | ----------------- |
| Inicial   | 0         | 0             | 0                 | 0                  | 0                 |
| Pós Exec. | n² loops  | 0             | 0                 | 0                  | Constante (\~16B) |

> ℹ️ A memória é gerenciada inteiramente na stack, com trocas feitas in-place. Nenhuma alocação dinâmica é usada.


---

## 4. Análise de Complexidade  

### Tabela de Desempenho  
| Caso         | Tempo (Big-O) | Espaço (Big-O) |  
|--------------|---------------|----------------|  
| Melhor       | O(n)          | O(1)           |  
| Médio/Pior   | O(n²)         | O(1)           |  


---  

## 5. Notas de Revisão  

### Revisão Pós-Implementação  
- **Otimização:** Adicionar flag `swapped` para evitar passagens desnecessárias em arrays parcialmente ordenados.  
- **Erros Comuns:**  
  - Acessar `tab[size]` (fora dos limites).  
  - Incrementar `i` ou `j` incorretamente.  

---  

## 6. Referências e Leituras Adicionais  
- [Bubble Sort - GeeksforGeeks](https://www.geeksforgeeks.org/bubble-sort/)   
- [Visualização Interativa](https://visualgo.net/en/sorting)  

---  

