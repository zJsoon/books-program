#include <stdio.h>
#include <stdlib.h>
#include "menus/menu.h"
#include "books/book.h"


int main(){
	lBook lb;
	//Book b;

	int op;

	lb.numBook = 0;

	do {
		system("cls");
		op = mostrarMenu();
		switch (op) {
			case 0:
				printf("Saliendo...");
				fflush(stdout);
				break;
			case 1:
				mostrarTitulos();
				mostrarLibros(lb);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				printf("La opción seleccionada es incorrecta.\n\n");
				fflush(stdout);
				break;
		}

	} while (op!=0);
	return 0;
}
