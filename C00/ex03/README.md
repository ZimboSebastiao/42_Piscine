**Exercício:** `ft_print_numbers.c` 
**Módulo:** `C00`
**Versão da Solução:** `1.0` 
**Área:** ``
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

Escreva uma função que exiba todos os dígitos, em uma única linha, em ordem crescente.
---
### Relevância
Fundamental para entender a relação entre valores numéricos e caracteres ASCII. 

---
## 2. Abordagem Técnica

### Estratégia Adotada

- **Algoritmo:** Iteração linear de `'0'` a `'9'` (valores ASCII 48 a 57).  
- **Complexidade:**  
  - **Tempo:** O(1) (10 iterações fixas).  
  - **Espaço:** O(1) (apenas uma variável contadora).  
- **Restrições:**  
  - Proibido usar `printf()` ou outras funções de E/S além de `write()`. 
--- 
### Pseudocódigo

```kotlin

Início do programa

  Definir i como caractere '0'

  Enquanto i for menor ou igual a '9':
      Escrever o caractere atual
      Incrementar i

Fim do programa



```
---
## 3. Implementação em C

```c

#include <unistd.h>

void	ft_print_numbers(void);

int main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}

void	ft_print_numbers(void)
{
	char i;

	i = '0';

	while (i <= '9')
	{
		write(1, &i, 1);
		i++;
	}
}

```
#### Saída Esperada
```bash
 0123456789
```
---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


> **Nota**: Como a função não aloca memória dinâmica, o uso de heap é inexistente. A função usa apenas a stack para armazenar o valor de i.
---
## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

- O código cumpre a especificação formal.
- Utiliza corretamente a codificação ASCII ao inicializar **i** com **'0'**.
- A iteração segue uma lógica simples e clara.

---

### Testes de Diagnóstico

- Verifica se os números são impressos em ordem crescente.
- Verifica se há exatamente 10 caracteres.
- Verifica se o programa não imprime espaços ou quebras de linha adicionais além do **\n** final.

---

### Análise Técnica

- O código é determinístico e seguro.
- Não há risco de buffer overflow ou comportamento indefinido.
- A modularização permite reutilizar **ft_print_numbers()** em outros contextos.

---

### Aprendizados Consolidados

- Como manipular caracteres como inteiros ('0' = 48 em ASCII).
- Uso de write() para saída padrão.
- Noções básicas de fluxo de controle com while.

---


## 5. Referências e Leituras Adicionais

- man 2 write – Manual da função write() no Linux.
- Linux Manual Pages: [write(2) — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- *ASCII Table and Description*: [ASCII Table](https://www.asciitable.com/)

[def]: #5-referências-e-leituras-adicionais