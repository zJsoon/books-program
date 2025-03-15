#include <stdio.h>
#include <stdlib.h>
#include "src/menus/menu.h"
#include "src/books/book.h"

int main() {
	lBook lb;
	Book b;

	int op,op1;

	iniBooks(&lb);
	loadBooksCSV("data/books.csv",&lb);

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
				case 1: // Ver todos los libros.
					mostrarTitulos();
					showBooks(lb);
					break;
				case 2: // Ver todos los libros del mismo año
					mostrarTitulos();

					showBookYear(lb, askYear());
					break;
				case 3: // Ver todos los libros del mismo autor
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

	copyBooksCSV("data/books.csv",lb);

	free(lb.aBook);

	return 0;
}
