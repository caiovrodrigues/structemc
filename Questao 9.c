#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Questão 9 - Crie uma struct chamada "Funcionario" com campos para nome, cargo, salário e data de admissão. 
Implemente funções para dar um aumento de salário e calcular quanto tempo um funcionário está na empresa.*/

typedef struct{
	char nome[20];
	char cargo[20];
	int date[3];
	float salario;
}Funcionario;

Funcionario funcionario[5];

int opcao, qtdFuncionarios = 2;

void home(){
	system("cls");
	printf("---------------- AREA DE FUNCIONARIOS ----------------\n\n");
	
	printf("1 - Listar funcionarios\n");
	printf("2 - Cadastrar funcionario\n");
	printf("3 - Aumentar salario\n");
	printf("4 - Calcular tempo de funcionario na empresa\n\n");
	
	printf("Selecione uma opcao: ");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			listarFuncionarios();
			break;
		case 2:
			cadastrarFuncionario();
			break;
		case 3:
			aumentarSalario();
			break;
	}
}

void listarFuncionarios(){
	int i;
	system("cls");
	printf("---------------- LISTA DE FUNCIONARIOS ----------------\n\n");
	for(i = 0; i < qtdFuncionarios; i++){
		printf("%s\n", funcionario[i].nome);
		printf("%d/%d/%d\n", funcionario[i].date[0], funcionario[i].date[1], funcionario[i].date[2]);
		printf("R$%.2f\n\n", funcionario[i].salario);
	}
	getch();
	home();
}

void cadastrarFuncionario(){
	system("cls");
	char nomeFuncionario[20];
	float salario;
	printf("---------------- CADASTRO DE FUNCIONARIOS ----------------\n\n");
	
	printf("Digite o nome do funcionario: ");
	scanf("%s",funcionario[qtdFuncionarios].nome);
	
	printf("\nSalario do funcionario: ");
	scanf("%f",&funcionario[qtdFuncionarios].salario);
	
	qtdFuncionarios++;
	
	printf("\nFuncionario cadastro com sucesso!");
	getch();
	home();
}

void aumentarSalario(){
	system("cls");
	int i;
	char nomeFuncionario[20];
	
	printf("---------------- AUMENTO DE SALARIO ----------------\n\n");
	
	printf("Digite o nome do funcionario: ");
	scanf("%s", nomeFuncionario);
	
	for(i = 0; i < qtdFuncionarios; i++){
		if(strcmp(funcionario[i].nome, nomeFuncionario) == 0){
			printf("\nDigite o novo salario: ");
			scanf("%f",&funcionario[i].salario);
			printf("Salario atualizado com sucesso!");
			getch();
			home();
			return;
		}
	}
	printf("\nFuncionario nao encontrado...");
	getch();
	home();
}

void criarFuncionarios(){
	strcpy(funcionario[0].nome, "Caio"); strcpy(funcionario[0].cargo, "Analista"); funcionario[0].date[0] = 10; funcionario[0].date[1] = 7; funcionario[0].date[2] = 2020; funcionario[0].salario = 4000;
	strcpy(funcionario[1].nome, "Lara"); strcpy(funcionario[1].cargo, "Tecnico"); funcionario[1].date[0] = 5; funcionario[1].date[1] = 12; funcionario[1].date[2] = 2022; funcionario[1].salario = 2000;
}

int main() {
	criarFuncionarios();
	home();
}
