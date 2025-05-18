**Exercício:** ft_print_comb2.c 
**Módulo:** C00
**Versão da Solução:** 1.0 
**Área:** `Loop, Funções, Matemática Discreta`
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

Escreva uma função que exiba todas as diferentes combinações de dois números
entre 0 e 99, em ordem crescente.
• Isso resulta em algo do tipo:

```bash
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99
```
---
### Relevância

Este exercício é uma extensão direta do **ft_print_comb**, trabalhando com pares de números de dois dígitos. Aqui entramos em contato com:

- Comparadores compostos (dois inteiros com relação de ordem).

- Lógica combinatória: quantas combinações de dois elementos distintos em uma faixa?

- Representação de dígitos de dois algarismos.

### Importância Matemática

O total de pares é uma aplicação clássica da combinação de elementos distintos com ordem:

- Temos 100 números de 0 a 99.

- Para cada **i**, imprimimos **j** tal que `j > i`.

- A quantidade de pares possíveis é a soma de uma PA

Ou seja, o programa gera 4950 combinações distintas.


### Valor Posicional no Sistema Decimal

#### Definição

No sistema decimal (base 10), **cada dígito de um número possui um valor que depende da sua posição**. Esse valor é sempre uma potência de 10:


Quando lidamos com números como `42` ou `07` no exercício, precisamos **exibir cada dígito separadamente** como caracteres. Para isso, usamos a ideia de valor posicional:

* Um número como `42` representa:

  * `4` na casa das dezenas → `4 * 10 = 40`
  * `2` na casa das unidades → `2 * 1 = 2`

Assim, podemos decompor qualquer número `n` (entre 0 e 99) como:

```c
char dezena = (n / 10) + '0';
char unidade = (n % 10) + '0';
```

Isso se baseia no **sistema decimal** (base 10), onde cada dígito ocupa uma posição com peso:

| Posição | Fator (potência de 10) |
| ------- | ---------------------- |
| Unidade | 10⁰ = 1                |
| Dezena  | 10¹ = 10               |
| Centena | 10² = 100              |

#### Exemplo aplicado ao código:

Suponha `n = 42`:

```c
dezena  = (42 / 10) + '0'  → 4 + '0' = '4'
unidade = (42 % 10) + '0'  → 2 + '0' = '2'
```

Logo, o par de caracteres `'4'` e `'2'` pode ser exibido corretamente com a função `write`.

> Essa decomposição é essencial para exibir corretamente os dois números em formato `XX YY`, como pedido no exercício.


- Os nomes **unidade**, **dezena**, **centena**, etc., representam **fatores multiplicadores** com base 10.

- A posição do dígito é **essencial** para saber qual fator aplicar.

- Isso é a base da aritmética, da computação binária (base 2), e até da conversão de números em linguagens como C.
---

## 2. Abordagem Técnica

### Estratégia Adotada

- Usaremos dois **int** para representar os dois números.

- O segundo número sempre começa de `i + 1`, evitando repetições e reversos (ex: 01 00).

- Cada número será separado em dezenas e unidades para conversão ASCII.

- Escreveremos manualmente cada caractere com 
**write**.

- **Algoritmo:** 
- **Complexidade:**  
  - Tempo: O(n^2) limitado a O(1) por ser um conjunto fixo de 4950 pares.  
  - Espaço: O(1), pois não usamos estruturas auxiliares.
- **Restrições:**  
  - Não utilizar bibliotecas além de `unistd.h`  
  - Somente a função `write` é permitida para saída  
--- 
### Pseudocódigo

```plaintext

Para i de 0 até 98:
   Para j de i+1 até 99:
      d1_i = i // 10
      d0_i = i % 10
      d1_j = j // 10
      d0_j = j % 10
      Imprimir d1_i, d0_i, ' ', d1_j, d0_j
      Se não for o último par:
         Imprimir ", "
```
---
## 3. Implementação em C

```c

#include <unistd.h>

void	ft_print_comb2(void);

int main(void)
{
	ft_print_comb2();
	write(1, "\n", 1);
	return (0);
}


void ft_print_comb2(void) {
    int i = 0;
    while (i <= 98) {  // i varia de 0 a 98 (inclusive)
        int j = i + 1;  // j sempre inicia após i
        while (j <= 99) {
            // Decomposição decimal de i
            char i_dezena = (i / 10) + '0';  // Divisão inteira
            char i_unidade = (i % 10) + '0'; // Resto da divisão
            
            // Decomposição decimal de j
            char j_dezena = (j / 10) + '0';
            char j_unidade = (j % 10) + '0';

            // Saída formatada
            write(1, &i_dezena, 1);
            write(1, &i_unidade, 1);
            write(1, " ", 1);
            write(1, &j_dezena, 1);
            write(1, &j_unidade, 1);

            // Controle de vírgulas (exceto no último par)
            if (!(i == 98 && j == 99)) {
                write(1, ", ", 2);
            }
            j++;
        }
        i++;
    }
}

```

#### Saída esperada
```bash
00 01, 00 02, ..., 98 99
```


---

### Gráficos de Desempenho (usando tabelas ASCII):

| Snapshot | Tempo (i) | Total (Bytes) | Heap Útil (Bytes) | Heap Extra (Bytes) | Stack (Bytes) |
|----------|-----------|----------------|--------------------|---------------------|----------------|
| 0        | 0         | 0              | 0                  | 0                   | 0              |


---


## 4. Notas de Revisão

### **Revisão Pós-Implementação:** 

- **Formatação de dois dígitos:** Dividimos por 10 para a dezena e usamos módulo para a unidade.

- **Não repetir nem inverter pares:** **j** sempre é maior que **i**.

- **Evitar ", " no final:** Verificação `if (!(i == 98 && j == 99))` impede a última vírgula.

---


## 5. Referências e Leituras Adicionais

* [Manual POSIX `write`](https://man7.org/linux/man-pages/man2/write.2.html)
* [Tabela ASCII Completa](https://www.asciitable.com/)
* [Combinatória - Khan Academy](https://pt.khanacademy.org/math/statistics-probability/counting-permutations-and-combinations/combinations-library/v/introduction-to-combinations)
* [PA e somatório - Geometria Analítica](https://www.somatematica.com.br/emedio/pa/pa3.php)
