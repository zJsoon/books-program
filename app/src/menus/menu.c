#include <stdio.h>
#include "menu.h"

int mostrarMenu(){
	int op;

	printf("1. Ver libreria\n");
	printf("2. Add libro\n");
	printf("3. Del libro\n");
	printf("4. Edit libro\n");
	printf("0. Salir\n");
	printf("Eliga una opcion: ");

	fflush(stdout);
	fflush(stdin);

	scanf("%i", &op);

	return op;
};

void mostrarTitulos(){
	printf("%14s%30s%30s%8s%40s%50s\n", "ISBN", "TITLE", "AUTOR", "AÑO", "DESCRIP", "OPINION");
	fflush(stdout);
};
