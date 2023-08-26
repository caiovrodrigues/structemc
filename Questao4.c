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
int contatosExistentes = 2;

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
	printf("--------- CONTATOS SALVOS NA SUA AGENDA ---------\n\n");
	int i = 0;
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
	
	printf("--------- BUSCAR CONTATO ---------\n\n");
	printf("Digite o nome: ");
	scanf("%s",&nameSearched);
	int p = 0;
	for(p = 0; nameSearched[p] != '\0'; p++){
		nameSearched[p] = tolower(nameSearched[p]);
	}
	int i = 0;
	for(i = 0; i < contatosExistentes; i++){
		if(strcmp(contato[i].nome, nameSearched) == 0){
			printf("\nCONTATO ENCONTRADO!!!\n\n");
			printf("Nome: %s\n", contato[i].nome);
			printf("Telefone: %s\n", contato[i].telefone);
		}
	}
}

Contact adicionarContatosPadrao(char nome[20], char telefone[11]){
	Contact C;
	strcpy(C.nome, nome);
	strcpy(C.telefone, telefone);
	return C;
}

int main() {
	contato[0] = adicionarContatosPadrao("Abner", "61995487777");
	contato[1] = adicionarContatosPadrao("carol", "61995036368");
	
	telaInicial();
	
//	Contato Contato2;
//	strcpy(Contato2.nome, "Abner");
//	Contato1.telefone = 61993487855;
}
