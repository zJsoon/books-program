#include <stdio.h>
#include "book.h"

void iniBooks(lBook *lb){
	lb->aBook = NULL;
	lb->numBook = 0;
}

void showBooks(lBook lb){
	int pos;
	for(pos=0;pos<lb.numBook;pos++){
		showBook(lb.aBook[pos]);
	}
}

void showBook(Book b){
	printf("%14s%30s%30s%8i%50s\n", b.ISBN, b.title, b.autor, b.year, b.desc);
	fflush(stdout);
}

void showBookYear(lBook lb, int year){
	int pos;
	for(pos=0;pos<lb.numBook;pos++){
		if(lb.aBook[pos].year==year){
			showBook(lb.aBook[pos]);
		}
	}
}
void loadBooksCSV(lBook *lb, Book b){

}

void addLibro(lBook *lb, Book b){
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

int askYear(){
	int op;
	printf("Selecciona el año en el que quieras filtrar: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &op);
	return op;
}

Book askBook(){
	Book b;

	printf("Introduce el ISBN del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &b.ISBN);
	printf("Introduce el título del libro: ");
	fflush(stdout);
	fflush(stdin);
	fgets(b.title, 30, stdin);
	printf("Introduce el autor del libro: ");
	fflush(stdout);
	fflush(stdin);
	fgets(b.autor, 30, stdin);
	printf("Introduce el año del libro: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &b.year);
	printf("Introduce una descripción breve del libro: ");
	fflush(stdout);
	fflush(stdin);
	fgets(b.desc, 50, stdin);

	return b;
}
