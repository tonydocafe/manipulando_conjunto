# Manipulção de cunjunto simples em C

definimos e manipulamos conjuntos usando uma estrutura de dados simples.

## Definição da Estrutura Conjunto:

A estrutura Conjunto é definida com um array de inteiros e um campo para armazenar o tamanho do conjunto.
## Funções para Manipulação de Conjuntos:

- inserirElemento
Adiciona um elemento ao final do array do conjunto.
Incrementa o tamanho do conjunto.

- pertenceConjunto
percorrendo o conjunto e verificando se o elemento está presente nele. E retornando 1 se for encontrado 0 caso ao contrario. 

- removeElemento
Encontra o elemento no conjunto e remove-o.
Desloca os elementos subsequentes para preencher o espaço vazio.
Decrementa o tamanho do conjunto.

- uniaoConjuntos
Cria um novo conjunto contndo todos os elementos dos dois conjuntos(sem duplicatas).

- intersecaoConjuntos
Cria um novo conjunto contendo apenas os elementos que estão presentes em ambos os conjuntos.

- diferencaConjuntos
Cria um novo conjunto contendo os elementos do primeiro conjunto que não estão presentes no segundo conjunto(denotada A − B).

- conjuntosIguais
Verifica se dois conjuntos têm o mesmo tamanho e se todos os elementos de um conjunto estão presentes no outro. 

- menorElemento
Percorre o conjunto para encontrar o menor valor e o retorna. 

- maiorElemento
Percorre o conjunto para encontrar o maior valor e o retorna. 

- conjuntoVazio
Verifica se o tamanho do conjunto é zero. 

-tamanhoConjunto
Retorna o número de elementos presentes no conjunto.
 
#### Função Principal (main):

- Cria dois conjuntos (conjunto1 e conjunto2).
- Insere elementos nos conjuntos.
- Exibe os elementos de cada conjunto.
- Calcula e exibe a união, interseção e diferença entre os conjuntos.
- Realiza testes como verificar se um elemento pertence ao conjunto, encontrar o menor e maior elemento, comparar se os conjuntos são iguais, obter o tamanho do conjunto e verificar se um conjunto está vazio.

#### Execução e saída

gcc conjuntos.c -o conjuntos
./conjuntos

Conjunto 1: 1 2 3 4 
Conjunto 2: 3 4 5 6 
3 pertence ao conjunto
4 pertence ao conjunto
União: 1 2 3 4 5 6 
3 pertence ao conjunto
4 pertence ao conjunto
Interseção: 3 4 
3 pertence ao conjunto
4 pertence ao conjunto
Diferença (conjunto1 - conjunto2): 1 2 
4 pertence ao conjunto
Testar se 4 pertence ao conjunto 1: Sim
Menor valor do conjunto 2: 3
Maior valor do conjunto 1: 4
Testar se os conjuntos 1 e 2 são iguais: Não
Tamanho do conjunto 2: 4
O conjunto 2 é vazio? Não

