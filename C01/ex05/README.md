**Exercício:** ft_putstr.c 
**Módulo:** C01
**Versão da Solução:** 1.0 
**Área:** `Manipulação de Strings, Entrada e Saída`
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

Escreva uma função que exiba uma string de caracteres no output padrão.

---

### Relevância

Esta função é parte fundamental de qualquer aplicação que envolva comunicação com o usuário. Compreender como exibir uma string sem recorrer a bibliotecas de mais alto nível é essencial para dominar a base da linguagem C e das interações com o sistema operacional.

---


## 2. Abordagem Técnica

### Estratégia Adotada

Percorrer a string caractere por caractere até encontrar o terminador nulo (`'\0'`) e, em cada iteração, enviar esse caractere para a saída padrão usando a função `write`.

- **Algoritmo:**  
  Iteração linear sobre os caracteres de uma string.

- **Complexidade:**  
  - Tempo: O(n), onde n é o comprimento da string.  
  - Espaço: O(1), uso constante de memória auxiliar (apenas um índice inteiro).

- **Restrições:**  
  - Não utilizar bibliotecas além de `unistd.h`.  
  - É proibido usar `printf`, `puts`, ou qualquer outra função além de `write`.

 
--- 
### Pseudocódigo

```bash
funcao ft_putstr(string)
    i ← 0
    enquanto string[i] for diferente de '\0'
        escrever string[i] na saída padrão
        i ← i + 1
fim da função

```
---
## 3. Implementação em C

```c

#include <unistd.h>

void	ft_putstr(char *str);

int	main()
{

	ft_putstr("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.");
	write(1, "\n", 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;

	while (str[i] != '\0')
	{

		write(1, &str[i], 1);
		i++;
	}
}

```

#### Saída esperada
```bash
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus...

```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Referências e Leituras Adicionais

* [Man page da função write(2)](https://man7.org/linux/man-pages/man2/write.2.html)
* [Normas da 42: Regras para funções e uso de bibliotecas](https://github.com/42School/norminette)
* K\&R - *The C Programming Language*, Brian Kernighan & Dennis Ritchie — Capítulo 1 e 2
* [Curso Harvard CS50 (Introdução à Ciência da Computação)](https://cs50.harvard.edu) — Semana 1
* [Entendendo descritores de arquivos em C](https://stackoverflow.com/questions/5860250/file-descriptor-vs-file-pointer)

