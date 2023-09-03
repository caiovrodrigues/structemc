#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x, y;
}Ponto;

void definePoint(Ponto *P, int xPoint, int yPoint){
	(*P).x = xPoint;
	(*P).y = yPoint;
}

int main(int argc, char *argv[]) {
	Ponto ponto;
	
	definePoint(&ponto, 7, 5);
	
	printf("Plano Cartesiano\n\n");
	printf("Posicao X = %d\n", ponto.x);
	printf("Posicao Y = %d\n", ponto.y);
	
	return 0;
}
