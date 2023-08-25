#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crie uma struct chamada "Pessoa" que contenha os seguintes campos: nome, idade e altura. Em seguida, 
escreva um programa que declare uma vari�vel do tipo Pessoa, preencha seus campos e imprima os valores.*/

typedef struct{
	char nome[20];
	int idade;
	float altura;
}Pessoa;

int main(){
	questao1();
}

void questao1(){
	Pessoa caio;
	char nome[20] = "caio";
	strcpy(caio.nome, nome);
	caio.idade = 15;
	caio.altura = 1.50;
	
	printf("%s tem %d anos e %.2f de altura", caio.nome, caio.idade, caio.altura);
}
















