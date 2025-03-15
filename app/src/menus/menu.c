#include <stdio.h>
#include "menu.h"

int mostrarMenu(){
	printf("|-----------------|\n");
	printf("|   LIBRERIA AIC  |\n");
	printf("|-----------------|\n");
	printf("| 1. Ver libreria |\n");
	printf("| 2. Add libro    |\n");
	printf("| 0. Salir        |\n");
	printf("|-----------------|\n");
	printf("Eliga una opcion: ");

	fflush(stdout);
	return pedirOp();
}

int mostrarLibreriaMenu(){
	printf("|------------------------------------|\n");
	printf("|       LIBRERIA AIC - FILTRADO      |\n");
	printf("|------------------------------------|\n");
	printf("| 1. Ver libreria entera             |\n");
	printf("| 2. Ver libreria filtrada por año   |\n");
	printf("| 3. Ver libreria filtrada por autor |\n");
	printf("| 0. Salir                           |\n");
	printf("|------------------------------------|\n");
	printf("Eliga una opcion: ");

	fflush(stdout);
	return pedirOp();
}

int pedirOp(){
	int op;
	fflush(stdin);
	scanf("%i", &op);
	return op;
}

void mostrarTitulos(){
	printf("%14s%30s%30s%8s%40s%50s\n", "ISBN", "TITLE", "AUTOR", "AÑO", "DESCRIP", "OPINION");
	fflush(stdout);
}
