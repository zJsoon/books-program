#ifndef BOOK_H_
#define BOOK_H_

typedef struct{
	char ISBN[14];
	char title[30];
	char autor[30];
	int year;
	char desc[40];
	char op[50];
} Book;

typedef struct{
	Book *aBook;
	int numBook;
} lBook;

void iniBooks(lBook *lb);

void showBooks(lBook lb);
void showBook(Book b);

void loadBooks();
Book askBook();
void addLibro(lBook *lb, Book b);

#endif /* BOOK_H_ */
