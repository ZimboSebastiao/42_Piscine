**Exercício:** ft_print_comb.c 
**Módulo:** C00
**Versão da Solução:** 1.0 
**Área:** `Loop, Funções`
**Dificuldade:** Iniciante  
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

Escreva uma função que exiba, em ordem crescente, todas as diferentes combinações
de três dígitos diferentes em ordem crescente - sim, a repetição é proposital.
• Isso resulta em algo do tipo:
```bash
012, 013, 014, ..., 789
```
- 987 fica de fora porque o 789 já está presente.
- 999 fica de fora porque o dígito 9 aparece mais de uma vez.

---
### Relevância

Esse exercício ajuda a entender:
- Loops aninhados (um while dentro de outro).
- Controle de variáveis (como garantir que os números sejam sempre crescentes).

Além disso, é um excelente exemplo de como pensar de forma sistemática para gerar todas as combinações possíveis respeitando regras.

---

## 2. Abordagem Técnica

### Estratégia Adotada

Para resolver, usaremos três loops aninhados, cada um controlando um dígito (**a**, **b**, **c**), onde:

- **a** é o primeiro dígito (0 a 7).

- **b** é o segundo dígito (sempre maior que a).

- **c** é o terceiro dígito (sempre maior que b).

**Por que a só vai até '7'?**

Porque se **a = '8'**, os próximos dígitos seriam **b = '9'** e **c** não teria como ser maior que **b**.

- **Algoritmo:** 
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
   a = '0'
   Enquanto a ≤ '7':
      b = a + 1
      Enquanto b ≤ '8':
         c = b + 1
         Enquanto c ≤ '9':
            Escrever a, b, c
            Se não for a última combinação:
               Escrever ", "
            c++
         b++
      a++
```
---
## 3. Implementação em C

```c

#include <unistd.h>

void ft_print_comb(void);

int main()
{
    ft_print_comb();
    return (0);
}

void ft_print_comb(void)
{
    char a;
    char b;
    char c;

    a = '0';
    while (a <= '7')  // Primeiro dígito (0 a 7)
    {
        b = a + 1;    // Segundo dígito começa depois de 'a'
        while (b <= '8')
        {
            c = b + 1;  // Terceiro dígito começa depois de 'b'
            while (c <= '9')
            {
                write(1, &a, 1);  // Mostra 'a'
                write(1, &b, 1);  // Mostra 'b'
                write(1, &c, 1);  // Mostra 'c'

                // Verifica se NÃO é a última combinação (789)
                if (a != '7' || b != '8' || c != '9')
                {
                    write(1, ", ", 2);  // Coloca vírgula e espaço
                }
                c++;
            }
            b++;
        }
        a++;
    }
}

```

#### Saída esperada
```bash
012, 013, 014, ..., 789
```

### Explicação Passo a Passo

1. **Inicialização** (`a = '0'`)
	- Começamos com a valendo '0'.
2. **Primeiro Loop** (`while (a <= '7'`)
	- **a** vai de **'0'** até **'7'** (pois **'8'** e **'9'** não têm dois dígitos maiores depois).
3. **Segundo Loop** (`while (b <= '8')`)
	- **b** sempre começa em `a + 1` (para garantir que seja maior que **a**).
	- Exemplo: Se `a = '0'`, **b** começa em **'1'**.
4. **Terceiro Loop** (`while (c <= '9')`)
	- **c** sempre começa em `b + 1` (para ser maior que **b**).
	- Exemplo: Se `b = '1'`, **c** começa em **'2'**.
5. **Condição para a Vírgula** (`if (a != '7' || ...)`)
	- Só coloca **", "** se não for a última combinação (`789`).
---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

- **Validação de última combinação:**
	- A condição `if (a != '7' || b != '8' || c != '9')` é essencial para evitar a impressão da última vírgula
- **Uso de char como números:**
	- Em C, os caracteres entre aspas simples ('0', '1'...) são tratados como números ASCII, por isso podemos fazer incrementos diretos como **a++**


---

### Testes de Diagnóstico

- Testar se a saída começa com **012**

- Testar se a saída termina com **789**

- Testar se nenhuma combinação se repete (ex: não há **321** ou **212**)

- Verificar se a vírgula e espaço estão corretos entre as combinações


---


### Aprendizados Consolidados

- Domínio do controle de fluxo com **while**

- Entendimento do uso de **char** como números

- A importância de testar limites (começo e fim de laços)

- Saber quando e como evitar uma saída extra (como a vírgula final)

- Prática de leitura e escrita de código enxuto, organizado e correto

---

## 5. Referências e Leituras Adicionais
* [Manual POSIX `write`](https://man7.org/linux/man-pages/man2/write.2.html)
* [Tabela ASCII Completa](https://www.asciitable.com/)

