/*
 * book.h
 *
 *  Created on: 20 feb 2025
 *      Author: Admin
 */

#ifndef BOOK_H_
#define BOOK_H_

typedef struct{
	char ISBN[14];
	char title[30];
	char autor[30];
	char fecha[11]; //dd-mm-yyyy
	char desc[40];
	char op[50];
} Book;

typedef struct{
	Book aBook[2000];
	int numBook;
} lBook;

void mostrarLibros(lBook lb);
void mostrarLibro(Book b);

#endif /* BOOK_H_ */
