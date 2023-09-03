#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Quest�o 10 - Crie uma struct chamada "Moeda" que possa armazenar valores em d�lares e euros. Escreva um programa 
que permita ao usu�rio escolher uma moeda e converter um valor entre d�lares e euros, usando a taxa de c�mbio 
atual*/

typedef struct{
	char nome[20];
	float cotacao;
}Moeda;


Moeda criarMoeda(char nome[20], float cotacao){
	Moeda M;
	strcpy(M.nome, nome);
	M.cotacao = cotacao;
	return M;
}

int main() {
	int opcao;
	float valor;
	
	Moeda Dolar = criarMoeda("Dolar", 1);
	
	Moeda Euro = criarMoeda("Euro", 0.9259);
	
	printf("1 - Dolar\n");
	printf("2 - Euro");
	
	printf("\n\nEscolha uma opcao: ");
	scanf("%d",&opcao);
	
	conversao();
	
	
}
