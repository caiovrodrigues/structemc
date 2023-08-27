#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct{
	char nome[20];
	char telefone[11];
}Contact;

Contact contato[10];

int escolha;
int contatosExistentes = 0;

void telaInicial(){
	system("cls");
	printf("--------- CONTATOS ---------\n\n");
	printf("1 - Adicionar contatos\n");
	printf("2 - Listar todos contatos\n");
	printf("3 - Buscar contato\n\n");
	
	printf("Selecione uma opcao: ");
	scanf("%d", &escolha);
	
	direcionarUsuario(escolha);
}

void direcionarUsuario(int escolha){
	switch(escolha){
		case 1:
			addContato();
			break;
		case 2:
			showContatos();
			break;
		case 3:
			searchContato();
			break;
		default:
			break;
	}
}

void showContatos(){
	system("cls");
	int i;
	printf("--------- CONTATOS SALVOS NA SUA AGENDA ---------\n\n");
	
	if(contatosExistentes == 0){
		printf("Nenhum contato encontrado...");
	}
	
	if(contatosExistentes > 0){
		printf("%d contatos salvos\n\n", contatosExistentes);
	}
	
	for(i = 0; i < contatosExistentes; i++){
		printf("%s - %s\n\n",contato[i].nome, contato[i].telefone);
	}
	
	getch();
	telaInicial();
}

void addContato(){
	system("cls");
	char name[20];
	char tel[11];
	
	printf("--------- ADICIONAR CONTATO ---------\n\n");
	
	printf("Nome: ");
	scanf("%s",&name);
	
	fflush(stdin);
	
	printf("Telefone: ");
	scanf("%s",&tel);
	
	strcpy(contato[contatosExistentes].nome, name);
	strcpy(contato[contatosExistentes].telefone, tel);
	
	contatosExistentes++;
	
	printf("\nContato adicionado com sucesso!!!");
	
	getch();
	
	telaInicial();
}

void searchContato(){
	system("cls");
	char nameSearched[20];
	int p, i;
	
	printf("--------- BUSCAR CONTATO ---------\n\n");
	
	printf("Digite o nome: ");
	scanf("%s",&nameSearched);
	
	for(p = 0; nameSearched[p] != '\0'; p++){
		nameSearched[p] = tolower(nameSearched[p]);
	}
	
	for(i = 0; i < contatosExistentes; i++){
		if(strcmp(contato[i].nome, nameSearched) == 0){
			mostrarContatoEncontrado(contato[i]);
			getch();
			telaInicial();
			return;
		}
	}
	
	printf("Contato nao encontrado...");
	getch();
	telaInicial();
	
}

void mostrarContatoEncontrado(Contact C){
	printf("\nCONTATO ENCONTRADO!!!\n\n");
	printf("Nome: %s\n", C.nome);
	printf("Telefone: %s\n", C.telefone);
}

Contact adicionarContatosPadrao(char nome[20], char telefone[11]){
	Contact pessoa;
	strcpy(pessoa.nome, nome);
	strcpy(pessoa.telefone, telefone);
	return pessoa;
}

int main() {
	Contact contato[0];
	contato[0] = adicionarContatosPadrao("Abner", "61995984477");
	
	telaInicial();
}
