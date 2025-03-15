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
	printf("%14s%30s%30s%8i%40s%50s\n", b.ISBN, b.title, b.autor, b.year, b.desc, b.op);
	fflush(stdout);
}

void loadBooks(lBook *lb, Book b){

}

Book askBook(){
	Book b;

	return b;
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
