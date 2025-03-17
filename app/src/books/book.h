#ifndef BOOK_H_
#define BOOK_H_

typedef struct{
	char ID[10];
	char ISBN[14];
	char title[50];
	char author[150];
	int year;
	char editorial[30];
	int edition;
	char key_words[50];
	char notes[150];
} Book;

typedef struct{
	Book *aBook;
	int numBook;

} lBook;

void iniBooks(lBook *lb);
void loadBooksCSV(char *csv, lBook *lb);
void copyBooksCSV(char *csv, lBook lb);

void showTitles();
void showBooks(lBook lb);
void showBook(Book b);
void showBookYear(lBook lb, int year);
void showBookAuthor(lBook lb, char *author);

int askYear();
char askAuthor();
Book askBook();
void addBook(lBook *lb, Book b);

#endif /* BOOK_H_ */
