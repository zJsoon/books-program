#include <stdio.h>
#include <stdlib.h>
#include "src/menus/menu.h"
#include "src/books/book.h"

int main() {
	lBook lb;
	Book b;

	int op,op1;

	iniBooks(&lb);

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
					printf("Volviendo menú principal...");
					fflush(stdout);
					break;
				case 1:
					mostrarTitulos();
					showBooks(lb);
					break;
				default:
					printf("La opción seleccionada es incorrecta.\n\n");
					fflush(stdout);
					break;
				}

			} while (op1 != 0);
			break;
		case 2:
			b = askBook();
			addLibro(&lb, b);
			break;
		default:
			printf("La opción seleccionada es incorrecta.\n\n");
			fflush(stdout);
			break;
		}

	} while (op != 0);

	free(lb.aBook);

	return 0;
}
