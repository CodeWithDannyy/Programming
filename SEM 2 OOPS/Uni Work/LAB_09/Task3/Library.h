#ifndef LIBRARY
#define LIBRARY
#include<iostream>
#include "Book.h"

class Library
{
    Book** books;
    int bookCount;
    int totalBooks;

    public:
        Library(int totalBooks) ;

        void addBook(Book* book);
        void removeBook(Book* book);
        void searchBook(string ISBN);

        ~Library();
};

#endif