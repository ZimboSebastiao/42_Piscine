**Exercício:** ft_strlen.c 
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Manipulação de Strings`
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

Escreva uma função que conte e retorne o número de caracteres em uma string.

---

### Relevância

A função `ft_strlen` é uma das funções fundamentais na manipulação de strings em C. Ela representa um exercício básico de iteração sobre arrays e compreensão do conceito de strings terminadas por `\0`, que é central na linguagem C.

---

## 2. Abordagem Técnica

### Estratégia Adotada

A abordagem utilizada foi iterar sobre cada caractere da string até encontrar o caractere nulo `\0`, que indica o fim da string.

- **Algoritmo:** Contagem linear por iteração  
- **Complexidade:**  
  - Tempo: O(n), onde *n* é o número de caracteres da string  
  - Espaço: O(1), pois usa apenas uma variável auxiliar de controle  
- **Restrições:**  
  - Não utilizar nenhuma biblioteca.


--- 

### Pseudocódigo

```bash
Função recebe um ponteiro para char (início da string)
Inicializa contador em zero
Enquanto o caractere atual for diferente de '\0':
    Incrementa o contador
Retorna o contador

```
---
## 3. Implementação em C

```c

#include <stdio.h>

int	ft_strlen(char *str);

int	main()
{
	printf("%d\n", ft_strlen("Lorem ipsum"));
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

```

#### Saída esperada
```bash
11

```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |



---

## 4. Referências e Leituras Adicionais

* [C Documentation - Strings (cplusplus.com)](https://cplusplus.com/reference/cstring/)
* K\&R — *The C Programming Language*, capítulo sobre arrays e strings
* [man strlen](https://man7.org/linux/man-pages/man3/strlen.3.html)
