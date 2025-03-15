#ifndef BOOK_H_
#define BOOK_H_

typedef struct{
	char ISBN[14];
	char title[30];
	char autor[30];
	int year;
	char desc[50];
} Book;

typedef struct{
	Book *aBook;
	int numBook;
} lBook;

void iniBooks(lBook *lb);

void showBooks(lBook lb);
void showBook(Book b);
void showBookYear(lBook lb, int year);

void loadBooksCSV(char *csv, lBook *lb);

int askYear();
Book askBook();
void addLibro(lBook *lb, Book b);

void copyBooksCSV(char *csv, lBook lb);

#endif /* BOOK_H_ */
