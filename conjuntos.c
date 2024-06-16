#include <stdio.h>
#include <stdlib.h>
#include<stbool.h>


#define TAM 100

typedef struct{
	int tamanho;
	int elemento[TAM];
}Conjunto;


void criarConjunto(Conjunto *conjunto){
	conjunto->tamanho = 0;
}

void inserirElemento(Conjunto *conjunto, int elemento){
	conjunto->elemento[conjunto->tamanho] = elemento;
	conjunto->tamanho++;
}

bool pertenceConjunto(Conjunto *conjunto, int elemento){
	for(int i = 0 ; i < conjunto->tamanho; i++) {
		if (elemento == conjunto->elemento[i]){
			printf("%i pertence ao conjunto\n",elemento);
			return true;
		}
	}
	return false;
}

void removeElemento(Conjunto *conjunto, int elemento){
	int achado = 0;
	for (int i = 0; i < conjunto->tamanho; i ++){
		if(elemento == conjunto->elemento[i]){
			achado = 1;
			for (int j = i ; j < conjunto->tamanho -1; j ++){
				conjunto->elemento[j] = conjunto->elemento[j+1];			}
			conjunto->tamanho--;
			break;
		}
	}
}

Conjunto uniaoConjuntos(Conjunto conjunto, Conjunto Nconjunto){
	Conjunto novo;
	criarConjunto(&novo);
	for (int i = 0 ; i < conjunto.tamanho; i ++){
		inserirElemento(&novo, conjunto.elemento[i]);
	}
	for (int i = 0 ; i < Nconjunto.tamanho; i ++){
		if(!pertenceConjunto(&novo,Nconjunto.elemento[i])){
		inserirElemento(&novo, Nconjunto.elemento[i]);
		}
	}
	return novo;
}

Conjunto intersecaoConjuntos(Conjunto conjunto, Conjunto Nconjunto){
	Conjunto novo;
	criarConjunto(&novo);
	for (int i = 0; i < conjunto.tamanho; i++){
		if (pertenceConjunto(&Nconjunto, conjunto.elemento[i])){
			inserirElemento(&novo,conjunto.elemento[i]);
		}
	}
	return novo;
}

Conjunto diferencaConjuntos(Conjunto conjunto, Conjunto Nconjunto){
	Conjunto novo;
	criarConjunto(&novo);
	for (int i = 0; i < conjunto.tamanho; i++){
		if (!pertenceConjunto(&Nconjunto, conjunto.elemento[i])){
			inserirElemento(&novo,conjunto.elemento[i]);
		}
	}
	return novo;
}

int conjuntosIguais(Conjunto conjunto, Conjunto Nconjunto){
	if(conjunto.tamanho != conjunto.tamanho){
		return 0 ;
	}
	for (int i = 0; i < conjunto.tamanho; i++){
		if (!pertenceConjunto(&Nconjunto, conjunto.elemento[i])){
			return 0;
		}
	}

	return 1;
}

int menorElemento(Conjunto conjunto){
	int menor = conjunto.elemento[0];
	for (int i = 1; i < conjunto.tamanho; i++){
		if (conjunto.elemento[i]< menor){
			menor = conjunto.elemento[i];
		}
	}
	return menor;
}

int maiorElemento(Conjunto conjunto){
	int maior = conjunto.elemento[0];
	for (int i = 1; i < conjunto.tamanho; i++){
		if (conjunto.elemento[i] > maior){
			maior = conjunto.elemento[i];
		}
	}
	return maior;
}

int conjuntoVazio(Conjunto conjunto){
	return (conjunto.tamanho == 0);
}
int tamanhoConjunto(Conjunto conjunto){
	return conjunto.tamanho;
}


int main() {
    Conjunto conjunto1, conjunto2;
    criarConjunto(&conjunto1);
    criarConjunto(&conjunto2);

    inserirElemento(&conjunto1, 1);
    inserirElemento(&conjunto1, 2);
    inserirElemento(&conjunto1, 3);
    inserirElemento(&conjunto1, 4);

    inserirElemento(&conjunto2, 3);
    inserirElemento(&conjunto2, 4);
    inserirElemento(&conjunto2, 5);
    inserirElemento(&conjunto2, 6);

    printf("Conjunto 1: ");
    for (int i = 0; i < conjunto1.tamanho; i++) {
        printf("%d ", conjunto1.elemento[i]);
    }
    printf("\n");

    printf("Conjunto 2: ");
    for (int i = 0; i < conjunto2.tamanho; i++) {
        printf("%d ", conjunto2.elemento[i]);
    }
    printf("\n");

    Conjunto uniao = uniaoConjuntos(conjunto1, conjunto2);
    printf("União: ");
    for (int i = 0; i < uniao.tamanho; i++) {
        printf("%d ", uniao.elemento[i]);
    }
    printf("\n");

    Conjunto intersecao = intersecaoConjuntos(conjunto1, conjunto2);
    printf("Interseção: ");
    for (int i = 0; i < intersecao.tamanho; i++) {
        printf("%d ", intersecao.elemento[i]);
    }
    printf("\n");

    Conjunto diferenca = diferencaConjuntos(conjunto1, conjunto2);
    printf("Diferença (conjunto1 - conjunto2): ");
    for (int i = 0; i < diferenca.tamanho; i++) {
        printf("%d ", diferenca.elemento[i]);
    }
    printf("\n");

    printf("Testar se 4 pertence ao conjunto 1: %s\n", pertenceConjunto(&conjunto1, 4) ? "Sim" : "Não");
    printf("Menor valor do conjunto 2: %d\n", menorElemento(conjunto2));
    printf("Maior valor do conjunto 1: %d\n", maiorElemento(conjunto1));
    printf("Testar se os conjuntos 1 e 2 são iguais: %s\n", conjuntosIguais(conjunto1, conjunto2) ? "Sim" : "Não");
    printf("Tamanho do conjunto 2: %d\n", tamanhoConjunto(conjunto2));
    printf("O conjunto 2 é vazio? %s\n", conjuntoVazio(conjunto2) ? "Sim" : "Não");

    return 0;
}
