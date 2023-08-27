#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Questão 6 - Crie uma struct chamada "Estudante" com campos para nome, matrícula e notas em três disciplinas. 
Implemente funções para calcular a média das notas e determinar se um aluno está aprovado (média maior ou igual a 7)*/

typedef struct{
	char nome[20];
	float notas[3];
}Estudante;

Estudante aluno[4];

int opcao, opcaoAluno;

void listarAlunos(){
	int i;
	for(i = 0; i < 4; i++){
		printf("ID %d \nNome: %s\nNota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\n\n", i + 1, aluno[i].nome, aluno[i].notas[0], aluno[i].notas[1], aluno[i].notas[2]);
	}
}

void calcularMedia(){
	system("cls");
	printf("---------------- MEDIA DO ALUNO ----------------\n\n");
	listarAlunos();
	printf("Digite o id de um aluno: ");
	scanf("%d", &opcaoAluno);
	
	showMediaAluno();
}

void showMediaAluno(){
	system("cls");
	float media = 0;
	media = (aluno[opcaoAluno - 1].notas[0] + aluno[opcaoAluno - 1].notas[1] + aluno[opcaoAluno - 1].notas[2]) / 3;
	printf("---------------- MEDIA DO ALUNO ----------------\n\n");
	
	printf("Nome: %s \nNota 1: %.2f \nNota 2: %.2f \nNota 3: %.2f\n", aluno[opcaoAluno - 1].nome, aluno[opcaoAluno - 1].notas[0], aluno[opcaoAluno - 1].notas[1], aluno[opcaoAluno - 1].notas[2]);
	printf("Media: %.2f\n", media);
	if(media >= 7){
		printf("APROVADO");
	}else{
		printf("REPPROVADO");
	}
	getch();
	main();
}

void criarAlunos(){
	strcpy(aluno[0].nome, "Caio"); aluno[0].notas[0] = 6; aluno[0].notas[1] = 7; aluno[0].notas[2] = 8;
	strcpy(aluno[1].nome, "Lara"); aluno[1].notas[0] = 5; aluno[1].notas[1] = 4; aluno[1].notas[2] = 9;
	strcpy(aluno[2].nome, "Beatriz"); aluno[2].notas[0] = 6; aluno[2].notas[1] = 8; aluno[2].notas[2] = 4.2;
	strcpy(aluno[3].nome, "Maria"); aluno[3].notas[0] = 9; aluno[3].notas[1] = 10; aluno[3].notas[2] = 8.8;
}

int main() {
	criarAlunos();
	system("cls");
	printf("---------------- AREA DO ESTUDANTE ----------------\n\n");
	
	printf("1 - Listar alunos\n");
	printf("2 - Calcular media de aluno\n\n");
	
	printf("Selecione uma das opcoes: ");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			system("cls");
			printf("---------------- LISTA DE ALUNOS ----------------\n\n");
			listarAlunos();
			getch();
			main();
			break;
		case 2:
			calcularMedia();
			break;
		default:
			printf("\nDigite uma opcao valida");
			getch();
			main();
			break;
	}
}
