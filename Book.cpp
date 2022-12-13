#include "Book.h"

Book::Book()
{}
Book::Book(string T, string A, string d, int x)
{
	title = T;
	author = A;
	domain = d;
	ISBN = x;
}