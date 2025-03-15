#include <stdio.h>
#include <stdlib.h>
#include "src/menus/menu.h"
#include "src/books/book.h"

int main() {
	lBook lb;
	//Book b;

	int op,op1;

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
			do {
				op1 = mostrarLibreriaMenu();
				switch (op1) {
				case 0:

					break;
				case 1:
					mostrarTitulos();
					mostrarLibros(lb);
				default:
					break;
				}

			} while (op1 != 0);
			break;
		case 2:
			break;
		default:
			printf("La opción seleccionada es incorrecta.\n\n");
			fflush(stdout);
			break;
		}

	} while (op != 0);
	return 0;
}
