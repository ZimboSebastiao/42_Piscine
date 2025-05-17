**Exercício:** ft_is_negative.c 
**Módulo:** C00
**Versão da Solução:** 1.0 
**Área:** `Estruturas condicionais, Funções`
**Dificuldade:** Iniciante  
<br>

---

## 📚 Sumário

1. [Objetivo e Contexto](#1-objetivo-e-contexto)  
2. [Abordagem Técnica](#2-abordagem-técnica)  
3. [Implementação em C](#3-implementação-em-c)  
4. [Comparação e Salto](#4-comparação-e-salto)  
5. [Notas de Revisão](#5-notas-de-revisão)  
6. [Referências e Leituras Adicionais](#6-referências-e-leituras-adicionais) 

---


## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que exiba ’N’ ou ’P’ segundo o sinal do inteiro passado como
parâmetro. Se n for negativo, exiba ’N’. Se n for positivo ou nulo, exiba ’P’.

---
### Relevância

Esse exercício é um ponto de partida para entender estruturas condicionais básicas em C, manipulação direta de saída com `write()`, e como decisões são traduzidas em baixo nível na arquitetura do processador.

---
## 2. Abordagem Técnica

### Estratégia Adotada

- **Algoritmo:** Comparação direta de um valor inteiro.
- **Complexidade:**  
  - Tempo: O(1)  
  - Espaço: O(1)  
- **Restrições:**  
  - Não utilizar bibliotecas além de `unistd.h`  
  - Somente a função `write` é permitida para saída  
--- 
### Pseudocódigo

```plaintext

Início da função:
    Se n < 0:
        Escreva 'N'
    Senão:
        Escreva 'P'
Fim
```
---
## 3. Implementação em C

```c

#include <unistd.h>


void	ft_is_negative(int n);

int main()
{
	ft_is_negative(0);
	write(1, "\n", 1);
	return (0);
}

void	ft_is_negative(int n)
{
	
	if ( n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}
```

#### Saída esperada
```bash
 P
```

---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---

## 4. Comparação e Salto

### O que acontece quando usamos if (n < 0)?

Quando escrevemos esse if em C: 

```c
if (n < 0)
	write(1, "N", 1);
else
	write(1, "P", 1);

```
O compilador (como o gcc) transforma o código C em uma linguagem chamada Assembly, que é uma forma mais próxima da linguagem de máquina. Depois, essa linguagem é convertida em código binário (0s e 1s) que o processador realmente entende e executa.

- **cmp**: compara dois valores

- **jl**: faz um "salto" se o número for menor (jump if less)

Mas o que isso significa na prática?

### Explicando por partes: o que faz o **cmp**?

Imagine que temos uma balança para comparar dois números.

No caso do nosso programa, queremos saber se o número **n** é menor que 0.

Então o comando de comparação fica assim:

```bash
cmp n, 0
```

Isso quer dizer:
“Compare o número n com 0 e me diga quem é maior, menor ou se são iguais”.

Mas atenção: o **cmp** não guarda nenhum valor. Ele só olha a diferença e atualiza uns **"sinais internos"** do processador, chamados de **flags**. Pense neles como lâmpadas que acendem dependendo do resultado:

💡 **Zero flag (ZF):** acende se o número for exatamente 0.

💡 **Sign flag (SF):** acende se o número for negativo.

💡 **Overflow flag (OF):** acende se der algum erro de sinal (ex: se o número for muito grande ou muito pequeno para caber ali).

Essas "lâmpadas" ajudam a decidir o que fazer depois.

Não existe nenhuma “lâmpada especial” **(flag)** especificamente para indicar que o número é positivo.

o processador consegue “saber” que o número é positivo observando que:

- O resultado **não é zero** → a Zero Flag (ZF) fica desligada.
- O resultado **não é negativo** → a Sign Flag (SF) também fica desligada.
- Não houve erro de sinal → a Overflow Flag (OF) também fica desligada.

Ou seja, quando comparamos um número positivo com zero, o processador conclui que ele é maior que zero porque:

- ZF = 0
- SF = 0
- OF = 0

E com isso ele sabe: “Ah, então esse número é positivo”.

### E o que é jl?

Depois de comparar, o processador precisa tomar uma decisão.

Ele faz isso com comandos chamados de salto condicional.
No nosso caso, ele usa:

```bash
jl destino_negativo
```

Isso quer dizer:
“Se o número for menor que 0, vá para o trecho de código chamado ‘destino_negativo’”.

O “jl” vem de “Jump if Less” ou seja, “salte se for menor”.

Caso contrário, ele continua lendo o próximo pedaço do código normalmente (que seria o “else”).

### Traduzindo tudo para português e C

O que o processador faz é mais ou menos assim:

```bash
compare n com 0
se n < 0, vá para a parte que imprime 'N'
senão, continue para imprimir 'P'
```

### Exemplo passo a passo

Suponha que **n = -3**:

- O processador executa: **cmp -3, 0**

- Ele percebe que -3 é menor que 0

- Acende o sinal de “negativo”

- A instrução **jl** vê esse sinal e salta para o trecho que imprime **'N'**

Agora, se **n = 5**:

- O processador executa: **cmp 5, 0**

- Ele percebe que 5 é maior que 0

- O sinal de “negativo” não acende

- O **jl** não salta, e o processador segue em frente e imprime 'P'

Você não precisa saber escrever Assembly agora mas entender que por trás do if, o processador:

1. Compara números

2. Acende “sinais internos”

3. Usa esses sinais para decidir se pula para outro trecho do programa

...te ajuda a pensar como um engenheiro de software que entende o que acontece “embaixo do capô”.

> “Cada vez que você escreve um if, o compilador pensa em cmp e jl para você.”

---

## 5. Notas de Revisão

### **Revisão Pós-Implementação:** 

- A função cumpre todos os requisitos do exercício.
- Foi utilizada a função write() com precisão.
- Código simples, direto e de fácil leitura.

---

### Testes de Diagnóstico

| Entrada | Saída Esperada |
| ------- | -------------- |
| -42     | N              |
| 0       | P              |
| 3       | P              |


---


### Aprendizados Consolidados

- Como instruções de comparação e salto funcionam em baixo nível
- Como um simples if se traduz em lógica de flags e saltos
- Uso de write() para saída direta na tela

---

## 6. Referências e Leituras Adicionais

* [x86-64 Assembly Jump Conditions](https://wiki.osdev.org/X86-64_Instruction_Encoding#Conditional_Jumps)
* [Manual do GCC: Como o código C vira Assembly](https://gcc.gnu.org/)
* [Documentação POSIX - write()](https://man7.org/linux/man-pages/man2/write.2.html)
