**Exercício:** `ft_print_alphabet.c` 
**Módulo:** `C00`
**Versão da Solução:** `1.0` 
**Área:** `ASCII, Tipos primitivos, Loop`
**Dificuldade:** `Iniciante`  
<br>

---
## 1. Objetivo e Contexto 

### Descrição Formal

Escreva uma função que exiba o alfabeto em minúscula, numa única linha, em ordem crescente, começando pela letra 'a'.

---
### Relevância

Ao escrever uma função que imprime o alfabeto na saída padrão usando simplesmente o **write**, aprendemos a estruturar um programa simples, entendemos como funcionam os loops **(while)** e o controle de fluxo, além de trabalhar com a tabela ASCII e a manipulação de caracteres como inteiros.

---
## 2. Abordagem Técnica

### Estratégia Adotada

- **Algoritmo:** algoritmo iterativo de complexidade constante.  
- **Complexidade:** `O(1)` tempo, `O(1)` espaço.  
- **Restrições:** Não utilizar funções de biblioteca além de `write()`.  
--- 
### Pseudocódigo

```kotlin

Início do programa

Função principal (main):
    Chamar a função imprimir_alfabeto
    Escrever um caractere de nova linha na saída
    Retornar 0

Função imprimir_alfabeto:
    Definir variável i como o valor numérico da letra 'a'

    Enquanto i estiver entre os valores de 'a' e 'z':
        Escrever o caractere correspondente a i na saída
        Incrementar i em 1

Fim do programa


```
---
## 3. Implementação em C

```c
#include <unistd.h>

void	ft_print_alphabet(void);

int main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	return (0);
}

void	ft_print_alphabet(void)
{
	int	i;

	i = 0 + 'a';

    while (i >= 'a' && i <= 'z')
    {
        write(1, &i, 1);
		i++;
    }
}

```
---

### Ciclo de vida do programa em C

O código implementado passa pelas seguintes etapas:

1. **Pré-processamento**
O pré-processador `(cpp)` interpreta diretivas como `#include <unistd.h>` e insere o conteúdo do cabeçalho no código.
	- **Tarefa:** Expande diretivas como `#include`, `#define`, `#ifdef`.
	- **Resultado:** Um código C puro, com tudo "resolvido".
	- **Exemplo:** `#include <unistd.h>` vira o conteúdo real do arquivo **unistd.h**.

> **Comando para ver essa etapa:**
```bash
$ gcc -E programa.c -o programa.i
```

2. **Compilação (frontend + middle-end) (cc1)**
O compilador (**gcc** ou **clang**) transforma o código C em **assembly** (linguagem de máquina simbólica). Ele interpreta instruções como **write(1, &i, 1);** e as converte em instruções de máquina (opcodes).
	- **Tarefa:**
		- **Frontend:** Analisa sintaxe e semântica (parser e analisador léxico).
		- **Middle-end:** Faz otimizações independentes de máquina (ex: remover código morto).
	- **Gera:** Código Assembly específico para a sua arquitetura.
	- **Exemplo:** **"a"** vira **97**, e depois **movl $97, -4(%rbp)**.

> **Comando para ver essa etapa:**
```bash
$ gcc -S programa.c -o programa.s
```
3. **Montagem*
O assembler converte o código assembly em código de máquina (binário), criando um arquivo objeto **.o**.
	- **Tarefa:** Pega o Assembly e converte para **código de máquina binário (opcodes)**.
	- **Gera:** Um **objeto binário** (arquivo **.o**) com instruções reais de máquina.

> **Comando para gerar o arquivo .o:**
```bash
$ gcc -c programa.c -o programa.o
```

> **Comando para ver essa etapa**
```bash
$ xxd -b programa.o
```

4. **Ligação (Linking)**
O linker junta os arquivos objeto e as bibliotecas necessárias (como a que contém a função write) em um único executável.
	- **Tarefa:** Junta vários arquivos **.o**, resolve símbolos (como funções externas), organiza seções e gera um **executável final** (como **a.out** ou **programa**).
	- **inclui:** Bibliotecas (como **libc**), função **main**, tabelas, segmentos (**.text**, **.data**, etc).
---

### Estrutura Interna do Compilador (como o GCC)
Um compilador completo como o GCC (GNU Compiler Collection) tem muitos subsistemas internos:

| Subsistema                      | Função                                                        |
| ------------------------------- | ------------------------------------------------------------- |
| **Lexical Analyzer (Scanner)**  | Lê os caracteres do código e transforma em **tokens**         |
| **Parser**                      | Organiza os tokens em **árvores de sintaxe abstrata (AST)**   |
| **Semantic Analyzer**           | Verifica tipos, escopos, coerência                            |
| **Intermediate Code Generator** | Constrói um código de nível intermediário (ex: RTL, SSA)      |
| **Optimizer**                   | Aplica otimizações de alto e médio nível                      |
| **Code Generator**              | Transforma o intermediário em **Assembly**                    |
| **Register Allocator**          | Escolhe em quais registradores colocar valores temporários    |
| **Assembler**                   | Converte Assembly em **código de máquina (opcodes binários)** |
| **Linker**                      | Junta tudo e forma o executável                               |
---
### O que o Kernel faz com `write()`
```c
write(1, &i, 1);
```
- **write** é uma chamada de sistema (syscall). Syscalls são interfaces entre espaço do usuário e espaço do kernel.
- No Linux, o número da syscall **write** é geralmente 1 (em x86_64).
- O kernel verifica:
	- Se o descritor **1** é válido (stdout).
	- Se o endereço **&i** está acessível (proteção de memória).
	- Se **1** byte pode ser escrito.
- O kernel copia o byte para o buffer do terminal e o repassa para o **driver do terminal**, que o exibe na tela.
---

### Memória: quanto ocupa i?
```c
int i = 0 + 'a';
```
- **i** é um int, que geralmente ocupa **4 bytes** em sistemas modernos (32 bits).
- Porém, o **write()** escreve apenas **1 byte**: `write(1, &i, 1);`.
- Isso significa: escreva o **byte menos significativo** de **i**, que contém a letra em ASCII.
---
### ASCII e representação binária
- **'a'** é igual a 97 em decimal = **01100001** em binário.
- O compilador traduz **'a'** diretamente para 97.
- A cada iteração, **i++** incrementa esse valor (98 = 'b', 99 = 'c', …, até 122 = 'z').
---
### O que acontece na RAM?
Durante a execução:
- A stack guarda a variável **i**.
- A cada iteração:
	- O valor de **i** é atualizado.
	- **write** pega 1 byte de **&i** (mesmo endereço, valor diferente).
	- O kernel lê e transmite esse byte ao terminal.
- O valor anterior de **i** não é apagado explicitamente, mas é sobrescrito.
---
### O terminal
O terminal (stdout = file descriptor 1) interpreta bytes recebidos e os renderiza como caracteres visuais. É o driver de vídeo ou subsistema gráfico que cuida da exibição.
---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---
## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

O programa estudado consistia em imprimir o alfabeto minúsculo no terminal utilizando apenas a syscall **write**. O foco foi a análise profunda do comportamento do código, da abstração do caractere **'a'** até sua representação física na memória e transmissão para o terminal via kernel.

---

### Testes de Diagnóstico

- **Verificação de execução:** saída correta do alfabeto no terminal com quebra de linha.
- **Validação de valores ASCII:** confirmação de que **'a'** = 97, **'z'** = 122.
- **Análise de memória:** compreensão de que **int i** ocupa 4 bytes, mas a syscall **write** envia apenas o byte menos significativo.
- **Exploração de ferramentas:** como xxd, gcc -S, e gdb.

---

### Análise Técnica

- **#include <unistd.h>:** necessário para acessar a função **write**, uma syscall, que delega o controle ao kernel para escrita em um file descriptor.
- **int i = 0 + 'a';:** inicializa **i** com 97 (valor decimal de **'a'**). Ainda que **i** ocupe 4 bytes, apenas o byte menos significativo é enviado via **write**.
- **write(1, &i, 1);:** escreve **1 byte** contido em **&i** no file descriptor **1** (stdout).
- **Representação binária:** **'a'** → 97 → **01100001**. A CPU trabalha apenas com esse padrão binário.
- **Memória:** o valor **i** armazena 97 em binário em uma das 4 posições (dependendo da endianness).
 A cada iteração, **i** é incrementado e a syscall **write** envia o novo caractere.

---

### Aprendizados Consolidados

1. A CPU **não interpreta números como humanos** apenas lida com **bits (0s e 1s)**.
2. O compilador traduz **'a'** para `97`, mas não imprime 97: ele gera instruções binárias que representam esse valor.
3. O valor decimal `97` é armazenado como **01100001** esse padrão é o que a CPU manipula.
4. **O compilador não é monolítico:** ele é composto por subsistemas que incluem:
	- Pré-processador (**cpp**)
	- Compilador (**cc1**)
	- Montador (**as**)
	- Ligador (**ld**)
5. Cada subsistema tem sua função na transformação do código-fonte C em um executável binário.
6. O processo de execução envolve **RAM**, **registradores**, **instruções da CPU** e o **kernel**, que coordena a escrita no terminal.
7. **O write(1, &i, 1);** extrai apenas **1 byte** do inteiro **i** o qual representa o caractere ASCII atual.
---

## 5. Referências e Leituras Adicionais

1. [Programming from the Ground Up](https://download-mirror.savannah.gnu.org/releases/pgubook/ProgrammingGroundUp-1-0-booksize.pdf).
2. [The C Programming Language – Kernighan e Ritchie (traduções e resumos gratuitos)](https://nostarch.com/download/CProgrammingLanguage.pdf)
3. [Learn C](https://www.learn-c.org)
4. [Modern C ](https://modernc.gforge.inria.fr/)
5. [Linkers and Loaders (John R. Levine)](https://www.iecc.com/linker/)
6. [Godbolt Compiler Explorer](https://godbolt.org/)
7. [Linux Syscalls Documentation](https://syscalls.kernelgrok.com/)
8. [The Linux Documentation Project](https://tldp.org/)
9. [GDB online](https://www.onlinegdb.com/online_c_compiler)