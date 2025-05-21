**Exercício:** ft_putnbr.c 
**Módulo:** C00
**Versão da Solução:** 1.0 
**Área:** `Impressão de inteiros`
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
Escreva uma função que exiba um número passado como parâmetro. A função
deverá ser capaz de representar a totalidade dos valores possíveis em uma variável
do tipo int.
---
### Relevância

Este exercício é uma introdução à manipulação de inteiros em baixo nível, sem o uso de bibliotecas de formatação como printf. Ele exercita:

- Representação binária de inteiros

- Recursão


### Importância Matemática

Este exercício aborda a representação de números com sinal em sistemas binários usando **complemento de dois**, que é a forma como os processadores atuais representam inteiros negativos. Também abre discussão sobre **limites de representatividade**, **overflow** e **intervalos de tipos primitivos**.

## 2. Abordagem Técnica

### Estratégia Adotada

1. **Identificar o sinal do número:**
	- Se for negativo, imprimir o `-` manualmente.
	- Converter o valor para positivo.
2. **Imprimir os dígitos:**
	- Utilizando recursão: dividindo o número por 10 até chegar ao dígito mais significativo.
	- Em cada "volta" da recursão, imprimir o dígito menos significativo com `% 10`.
3. **Tratar o caso extremo:** **INT_MIN** (valor mínimo de um int) não pode ser convertido para positivo, pois ultrapassa **INT_MAX**. Esse caso é tratado de forma especial.

- **Complexidade:**  
  - Tempo: O(n), onde n é o número de dígitos de `nb` (máximo 10 em int de 32 bits)
  - Espaço: O(n) na pilha por causa da recursão
- **Restrições:**  
  - Não utilizar bibliotecas além de `unistd.h`  
  - Somente a função `write` é permitida para saída  

--- 

### Pseudocódigo

```plaintext
Se nb == -2147483648
    escrever diretamente a string "-2147483648"
Senão se nb < 0
    escrever o caractere '-'
    nb = -nb

Se nb >= 10
    chamar ft_putnbr(nb / 10)

c = nb % 10 + '0'
escrever c na saída
```
---
## 3. Implementação em C

```c

#include <unistd.h>

void	ft_putnbr(int nb);

int main()
{
	ft_putnbr(-42);
	write(1, "\n", 1);
	return (0);
}

void	ft_putnbr(int nb)
{
	char	c;

		if (nb == -2147483648)
		{
			write (1, "-2147483648", 11);
			return;
		}

		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
		}
		c = nb % 10 + '0';
		write(1, &c, 1);

}


```

#### Saída esperada
```bash
ft_putnbr(-42) -> -42
ft_putnbr(0)   -> 0
ft_putnbr(123) -> 123
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |

---

### Análise Interna e Kernel

- A função `write` realiza uma `system call` (chamada de sistema) para o kernel Linux.

- O kernel então envia os bytes (no caso, caracteres ASCII) ao **buffer de saída padrão**, normalmente vinculado ao terminal.

- Isso significa que cada caractere escrito por `write` passa da aplicação → chamada de sistema → kernel → driver de terminal → terminal.

### Papel do processador

- O processador executa as instruções como "subtrair", "comparar", "desviar se menor que zero" etc., baseando-se na **representação binária** do valor de **nb**.

- Para números negativos, o processador interpreta os bits em **complemento de dois**.

- Por isso **-42** é armazenado como **11111111 11111111 11111111 11010110** em 32 bits.

## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

✅ Coberto todos os casos do intervalo do tipo int.

✅ Corrigida exceção para INT_MIN.

✅ Uso de write garantido e estável.

⚠️ Limitação: não imprime long ou maiores.

✅ Recursão segura devido à profundidade limitada a 10 chamadas (10 dígitos).


---



## 5. Referências e Leituras Adicionais

* [man write(2)](https://man7.org/linux/man-pages/man2/write.2.html)
* [Two's Complement - Wikipedia](https://en.wikipedia.org/wiki/Two%27s_complement)
* [System Calls - Linux Kernel Docs](https://docs.kernel.org/userspace-api/syscalls.html)
* [Representação binária em C - Embedded Artistry](https://embeddedartistry.com/blog/2018/04/23/how-integers-are-stored-in-memory/)


