#include <stdio.h>
#include "menu.h"

int showMenu(){
	printf("|-----------------|\n");
	printf("|   LIBRERIA AIC  |\n");
	printf("|-----------------|\n");
	printf("| 1. Ver libreria |\n");
	printf("| 2. Add libro    |\n");
	printf("| 0. Salir        |\n");
	printf("|-----------------|\n");
	printf("Eliga una opcion: ");

	fflush(stdout);
	return askOP();
}

int showLibraryMenu(){
	printf("|-------------------------------------|\n");
	printf("|        LIBRERIA AIC - FILTRADO      |\n");
	printf("|-------------------------------------|\n");
	printf("| 1. Ver libreria entera              |\n");
	printf("| 2. Ver libreria filtrada por year   |\n");
	printf("| 3. Ver libreria filtrada por autor  |\n");
	printf("| 0. Salir                            |\n");
	printf("|-------------------------------------|\n");
	printf("Eliga una opcion: ");

	fflush(stdout);
	return askOP();
}

int askOP(){
	int op;
	fflush(stdin);
	scanf("%i", &op);
	return op;
}


