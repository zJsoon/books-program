#include <stdio.h>
#include <stdlib.h>

#include "src/menus/menu.h"
#include "src/books/book.h"

int main() {
	lBook lb;
	Book b;

	int op, op1;

	iniBooks(&lb);
	loadBooksCSV("data/books.csv", &lb);

	do {
		system("cls");
		op = showMenu();
		switch (op) {
		case 0:
			printf("Saliendo...\n");
			fflush(stdout);
			break;
		case 1:
			do {
				op1 = showLibraryMenu();
				switch (op1) {
				case 0:
					printf("Volviendo menú principal...\n");
					fflush(stdout);
					break;
				case 1:
					showTitles();
					showBooks(lb);
					break;
				case 2:
					showBookYear(lb, askYear());
					break;
				case 3:
					showBookYear(lb, askAuthor());
					break;
				default:
					printf("La opción seleccionada es incorrecta.\n\n");
					fflush(stdout);
					break;
				}

			} while (op1 != 0);
			break;
		case 2:
			b = askBook(lb);
			addBook(&lb, b);
			break;
		default:
			printf("La opción seleccionada es incorrecta.\n\n");
			fflush(stdout);
			break;
		}

	} while (op != 0);

	copyBooksCSV("data/books.csv", lb);

	free(lb.aBook);

	return 0;
}
