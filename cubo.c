#include<stdio.h>

typedef struct{
	double lado;
} Cubo;


void inicializarCubo(Cubo *cubo, double lado){
	cubo->lado = lado;
	printf("Lado : %.2f \n",cubo->lado);
	printf("Area : %.2f \n",6*(cubo->lado * cubo->lado));
	printf("Volume : %.2f\n",cubo->lado*cubo->lado*cubo->lado);

}


int main(){
	Cubo cubo;
	inicializarCubo(&cubo,5);

}
