#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Questão 8 - Crie uma struct chamada "Produto" com campos para nome, preço e quantidade em estoque. Escreva um 
programa que permita ao usuário comprar produtos, atualizando o estoque e calculando o total da compra*/

typedef struct{
	int cod;
	char nome[20];
	float preco;
	int qtdComprada;
	int qtdEstoque;
}Produto;

Produto produtos[5];

int produtosComprados[20], opcao, p;

float total = 0;

void telaInicial(){
	system("cls");
	printf("---------------- AREA DO ESTUDANTE ----------------\n\n");
	
	printf("1 - Ver produtos\n");
	printf("2 - Ir para o carrinho\n\n");
	printf("Valor total: R$%.2f", total);
	
	printf("\n\nSelecione uma opcao: ");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			listarProdutos();
			break;
		case 2:
			mostrarCarrinho();
			break;
		default:
			telaInicial();
			break;
	}
}

void listarProdutos(){
	int i, codFruta;
	system("cls");
	printf("------------ PRODUTOS ------------\n\n");
	
	for(i = 0; i < 5; i++){
		printf("Codigo: %d\n", produtos[i].cod);
		printf("%s\n", produtos[i].nome);
		printf("R$%.2f\n", produtos[i].preco);
		printf("Estoque: %d\n\n", produtos[i].qtdEstoque);
	}
	
	printf("\nDigite 0 para voltar ou o codigo da fruta para adicionar ao carrinho: ");
	scanf("\n%d",&codFruta);
	
	if(codFruta == 0){
		telaInicial();
	}
	if(codFruta > 0 && codFruta < 6){
		produtosComprados[p] = codFruta - 1;
		p++;
		total += produtos[codFruta - 1].preco;
		produtos[codFruta - 1].qtdEstoque--;
		printf("%s adicionado ao carrinho...", produtos[codFruta - 1].nome);
		getch();
		listarProdutos();
	}else{
		printf("Esse produto nao existe");
		getch();
		listarProdutos();
	}
}

void mostrarCarrinho(){
	int i;
	int toggle;
	system("cls");
	
	printf("------------ SEU CARRINHO ------------\n\n");
	printf("%d produtos no carrinho\n\n", p);
	for(i = 0; i < p; i++){
		printf("%s\n", produtos[produtosComprados[i]].nome);
		printf("R$%.2f\n\n", produtos[produtosComprados[i]].preco);
	}
	
	printf("Valor total: R$%.2f\n", total);
	
	printf("\nDigite 0 para continuar comprando ou 1 para confirmar a compra: ");
	scanf("%d",&toggle);
	
	if(toggle == 1){
		system("cls");
		printf("Compra realizada!");
		getch();
		exit(0);
	}else{
		telaInicial();
	}
}

void criarProdutos(){
	produtos[0].cod = 1; strcpy(produtos[0].nome, "Arroz"); produtos[0].preco = 27.99; produtos[0].qtdEstoque = 10;
	produtos[1].cod = 2; strcpy(produtos[1].nome, "Sal"); produtos[1].preco = 3.79; produtos[1].qtdEstoque = 10;
	produtos[2].cod = 3; strcpy(produtos[2].nome, "Chocolate"); produtos[2].preco = 6.99; produtos[2].qtdEstoque = 10;
	produtos[3].cod = 4; strcpy(produtos[3].nome, "Detergente"); produtos[3].preco = 2.29; produtos[3].qtdEstoque = 10;
	produtos[4].cod = 5; strcpy(produtos[4].nome, "Pote Tupperware"); produtos[4].preco = 33.99; produtos[4].qtdEstoque = 10;
}

int main() {
	criarProdutos();
	telaInicial();
}
