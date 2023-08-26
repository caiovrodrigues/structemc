#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	char nome[20];
	int idade;
	float altura;
}Pessoa;

void imprimePerson(Pessoa P){
	printf("%s tem %d anos e %.2f de altura", P.nome, P.idade, P.altura);
}

void setPerson(Pessoa *P, char nome[20], int idade, float altura){
	strcpy(P->nome, nome);
	(*P).idade = idade;
	P->altura = altura;
}

int main() {
	Pessoa Caio;
	
	setPerson(&Caio, "Caio", 22, 1.50);
	imprimePerson(Caio);
}

//void imprimePerson(Pessoa P){
//	printf("%s tem %d anos e %.2f de altura", P.nome, P.idade, P.altura);
//}
//
//Pessoa setPerson(char nome[20], int idade, float altura){
//	Pessoa P;
//	strcpy(P.nome, nome);
//	P.idade = idade;
//	P.altura = altura;
//	return P;
//}
//
//int main() {
//	Pessoa Caio;
//	
//	Caio = setPerson("Caio", 22, 1.50);
//	imprimePerson(Caio);
//}
