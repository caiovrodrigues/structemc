#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crie uma struct chamada "Livro" com campos para título, autor e ano de publicação. Escreva um programa 
que permita ao usuário adicionar informações de livros, listar todos os livros cadastrados e buscar livros por autor*/

typedef struct{
	int id;
	char titulo[20];
	char autor[20];
	char anoPublicado[20];
	char informacoes[20];
	int existInfo;
}Livro;
Livro livro[5];

int escolha, idLivro;
char infoText[20], nomeAutor[20];

void telaInicial(){
	system("cls");
	printf("--------- Biblioteca ---------\n\n");
	printf("1 - Adicionar informacoes\n");
	printf("2 - Listar todos livros\n");
	printf("3 - Buscar livros por autor\n\n");
	
	printf("Selecione uma opcao: ");
	scanf("%d", &escolha);
	switchEscolha();
}

void switchEscolha(){
	switch(escolha){
		case 1:
			listarLivros();
			printf("\n\nDigite o ID do livro para adicionar informacoes: ");
			scanf("%d", &idLivro);
			
			changeInfo();
			break;
		case 2:
			listarLivros();
			getch();
			telaInicial();
			break;
		case 3:
			buscarLivros();
			break;
		default:
			break;
	}
}

void listarLivros(){
	system("cls");
	printf("--------- LIVROS REGISTRADOS ---------\n\n");
	
	int i;
	for(i = 0; i < 5; i++){
		printf("ID: %d\n", livro[i].id);
		printf("Livro: %s\n", livro[i].titulo);
		printf("Autor: %s\n", livro[i].autor);
		if(livro[i].existInfo == 1){
			printf("Comentarios: %s\n\n", livro[i].informacoes);
		}else{
			printf("\n");
		}
	}
}

void changeInfo(){
	system("cls");
	printf("--------- ADICIONANDO COMENTARIOS %s ---------\n\n", livro[idLivro - 1].titulo);
	
	printf("Digite seu comentario: ");
	scanf("%s",infoText);
	
	strcpy(livro[idLivro - 1].informacoes, infoText);
	livro[idLivro - 1].existInfo = 1;
	printf("\nVoltar...");
	getch();
	telaInicial();
}

void buscarLivros(){
	int i;
	system("cls");
	
	printf("--------- BUSCAR LIVROS POR AUTOR ---------\n\n");
	
	printf("Digite o nome do autor: ");
	scanf("%s", nomeAutor);
	
	for(i = 0; i < 5; i++){
		if(strcmp(livro[i].autor, nomeAutor) == 0){
			printf("\nAutor encontrado!!\n\n");
			printf("Livro: %s\n", livro[i].titulo);
			printf("Autor: %s", livro[i].autor);
			getch();
			telaInicial();
			return;
		}
	}
	printf("Autor nao encontrado");
	getch();
	telaInicial();
}

Livro criandoLivro(){
	livro[0].id = 1; strcpy(livro[0].titulo, "Livro A"); strcpy(livro[0].autor, "Gabriela");
	livro[1].id = 2; strcpy(livro[1].titulo, "Livro B"); strcpy(livro[1].autor, "Joao");
	livro[2].id = 3; strcpy(livro[2].titulo, "Livro C"); strcpy(livro[2].autor, "Pedro");
	livro[3].id = 4; strcpy(livro[3].titulo, "Livro D"); strcpy(livro[3].autor, "Lara");
	livro[4].id = 5; strcpy(livro[4].titulo, "Livro E"); strcpy(livro[4].autor, "Roger");
}

int main() {
	criandoLivro();
	
	telaInicial();
}
