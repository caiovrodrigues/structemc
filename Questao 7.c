#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Questão 7 - Crie uma struct chamada "ContaBancaria" com campos para nome do titular, número da conta e saldo. 
Implemente funções para depositar, sacar e verificar o saldo.*/

typedef struct{
	char nome[20];
	int conta;
	float saldo;
}ContaBancaria;

ContaBancaria Conta;

int opcao;

void telaHome(){
	system("cls");
	printf("------------ BANCO DA ESPANHA ------------\n\n");
	
	printf("1 - Depositar\n");
	printf("2 - Sacar\n");
	printf("3 - Verificar saldo\n\n");
	
	printf("Selecione uma opcao: ");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			system("cls");
			depositar();
			break;
		case 2:
			sacar();
			break;
		case 3:
			saldo();
			break;
		default:
			break;
	}
}

void depositar(){
	system("cls");
	float valor;
	printf("------------ DEPOSITO (CONTA: %s) ------------\n\n", Conta.nome);
	
	printf("Valor do deposito: ");
	scanf("%f",&valor);
	
	Conta.saldo += valor;
	printf("\nValor depositado com sucesso!");
	getch();
	telaHome();	
}

void sacar(){
	system("cls");
	float valor;
	printf("------------ SACAR (CONTA: %s) ------------\n\n", Conta.nome);
	
	printf("Valor a ser sacado: ");
	scanf("%f", &valor);
	
	if(valor > Conta.saldo){
		printf("\nSaldo insuficiente...");
		getch();
		telaHome();
	}else{
		Conta.saldo -= valor;
		printf("\nSaque realizado com sucesso...");
		getch();
		telaHome();
	}
}

void saldo(){
	system("cls");
	printf("------------ SALDO (CONTA: %s) ------------\n\n", Conta.nome);
	
	printf("Titular: %s\n", Conta.nome);
	printf("Conta: %d\n", Conta.conta);
	printf("Saldo: R$%.2f", Conta.saldo);
	
	getch();
	telaHome();
}

int main() {
	strcpy(Conta.nome, "CAIO");
	Conta.conta = 12345;
	Conta.saldo = 1000;
	
	telaHome();
}
