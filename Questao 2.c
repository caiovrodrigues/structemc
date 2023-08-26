#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char letra[1];
	int inteiro;
	float flutuante;
}Tipo;

void imprimir(Tipo V){
	printf("Letra: %s, Inteiro: %d, Float: %.1f\n\n", V.letra, V.inteiro, V.flutuante);
}

Tipo setPonto(char letra[1], int inteiro, float flutuante){
	Tipo V;
	strcpy(V.letra, letra);
	V.inteiro = inteiro;
	V.flutuante = flutuante;
	return V;
}

int main(){
	Tipo Valor1;
	Valor1 = setPonto("a", 1, 1.1);
	imprimir(Valor1);
	
	Tipo Valor2;
	Valor2 = setPonto("b", 2, 2.1);
	imprimir(Valor2);
	
	Tipo Valor3;
	Valor3 = setPonto("c", 3, 3.1);
	imprimir(Valor3);
	
	Tipo Valor4;
	Valor4 = setPonto("d", 4, 4.1);
	imprimir(Valor4);
	
	Tipo Valor5;
	Valor5 = setPonto("e", 5, 5.1);
	imprimir(Valor5);
}
