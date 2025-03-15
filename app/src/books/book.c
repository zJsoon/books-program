#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

void iniBooks(lBook *lb) {
	lb->aBook = NULL;
	lb->numBook = 0;
}

void loadBooksCSV(char *csv, lBook *lb) {
	char linea[1000];
	FILE *pf;
	Book b;

	pf = fopen(csv, "r");

	if (pf != (FILE*) NULL) {
		while (fscanf(pf, "%s", linea) != EOF) {
			char *ISBN = strtok(linea, ";");
			char *title = strtok(NULL, ";");
			char *autor = strtok(NULL, ";");
			char *year = strtok(NULL, ";");
			char *desc = strtok(NULL, "");

			strcpy(b.ISBN, ISBN);
			strcpy(b.title, title);
			strcpy(b.author, autor);
			b.year = atoi(year);
			strcpy(b.desc, desc);

			addBook(lb, b);
		}
		fclose(pf);
	}
}

void copyBooksCSV(char *csv, lBook lb) {
	FILE *pf = fopen(csv, "w");

	if (pf != (FILE*) NULL) {
		for (int i = 0; i < lb.numBook; i++) {
			Book b = lb.aBook[i];
			fprintf(pf, "%s;%s;%s;%d;%s\n", b.ISBN, b.title, b.author, b.year,
					b.desc);
		}
		printf("Datos guardados en %s correctamente.\n", csv);
		fflush(stdout);
	} else {
		perror("Error al abrir el archivo.\n");
	}

	fclose(pf);
}

void showTitles() {
	printf("%14s%50s%30s%8s%150s\n", "ISBN", "TITLE", "AUTOR", "AÑO",
			"DESCRIP");
	fflush(stdout);
}

void showBooks(lBook lb) {
	int pos;
	for (pos = 0; pos < lb.numBook; pos++) {
		showBook(lb.aBook[pos]);
	}
}

void showBook(Book b) {
	printf("%14s%50s%30s%8i%150s\n", b.ISBN, b.title, b.author, b.year, b.desc);
	fflush(stdout);
}

void showBookYear(lBook lb, int year) {
	int pos;
	showTitles();
	for (pos = 0; pos < lb.numBook; pos++) {
		if (lb.aBook[pos].year == year) {
			showBook(lb.aBook[pos]);
		}
	}
}

void showBookAuthor(lBook lb, char *author) {
	int pos;
	showTitles();
	for (pos = 0; pos < lb.numBook; pos++) {
		if (strcmp(lb.aBook[pos].author, author) == 0) {
			showBook(lb.aBook[pos]);
		}
	}
}

int askYear() {
	int yr;
	printf("Selecciona el año en el que quieras filtrar: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &yr);
	return yr;
}

char askAuthor() {
	char author;

	printf("Selecciona el autor/a en el que quieras filtrar: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", &author);

	return author;
}

Book askBook() {
	Book b;

	printf("Introduce el ISBN del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", b.ISBN);
	printf("Introduce el título del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", b.title);
	printf("Introduce el autor del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", b.author);
	printf("Introduce el año del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &b.year);
	printf("Introduce una descripción breve del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", b.desc);

	return b;
}

void addBook(lBook *lb, Book b) {
	int i;

	if (lb->aBook == NULL) {
		lb->aBook = malloc(1 * sizeof(Book));
	} else {
		Book *aux = malloc(lb->numBook * sizeof(Book));
		for (i = 0; i < lb->numBook; i++) {
			aux[i] = lb->aBook[i];
		}
		free(lb->aBook);
		lb->aBook = malloc((lb->numBook + 1) * sizeof(Book));
		for (i = 0; i < lb->numBook; i++) {
			lb->aBook[i] = aux[i];
		}
		free(aux);
	}
	lb->aBook[lb->numBook] = b;
	lb->numBook++;
}
