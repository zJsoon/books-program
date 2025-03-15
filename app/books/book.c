/*
 * book.c
 *
 *  Created on: 20 feb 2025
 *      Author: Admin
 */

#include <stdio.h>
#include "book.h"

void mostrarLibros(lBook lb){
	int pos;
	for(pos=0;pos<lb.numBook;pos++){
		mostrarLibro(lb.aBook[pos]);
	}
};
void mostrarLibro(Book b){
	printf("%14s%30s%30s%11s%40s%50s\n", b.ISBN, b.title, b.autor, b.fecha, b.desc, b.op);
	fflush(stdout);
};
