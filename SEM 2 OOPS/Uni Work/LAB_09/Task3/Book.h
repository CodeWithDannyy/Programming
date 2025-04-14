#ifndef BOOK
#define BOOK

#include<iostream>
using namespace std;

class Book
{
    string title;
    string author;
    string ISBN;

    public:
        Book(string title, string author, string ISBN) ;
            
        string getTitle() const;
        string getAuthor() const;
        string getISBN() const;
};

#endif