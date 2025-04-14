#include<iostream>
#include "Library.h"
using namespace std;

Library::Library(int totalBooks) : totalBooks(totalBooks), bookCount(0)
{
    books = new Book*[totalBooks];
}

void Library::addBook(Book* book)
{
    if(bookCount < totalBooks)
    {
        books[bookCount++] = book;
        cout << "Book " << book->getTitle() << " added." << endl;
    }
    else
        cout << "Cant add more books" << endl;
}

void Library::removeBook(Book* book)
{
    for(int i = 0; i < bookCount; i++)
    {
        if(book->getISBN() == books[i]->getISBN())
        {
            for(int j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j +1 ];
            }
            bookCount--;
            cout << "Book " << book->getTitle() << " removed." << endl;
            return;
        }
    }
    cout << "Book not found for removal" << endl;
}

void Library::searchBook(string ISBN)
{
    bool found = false;
    for(int i = 0; i < bookCount; i++)
    {
        if(ISBN == books[i]->getISBN())
        {
            found = true;
            cout << "Book Found!\n Here are the book details: " << endl;
            cout << "Title  : " << books[i]->getTitle() << endl;
            cout << "Author : " << books[i]->getAuthor() << endl;
            cout << "ISBN   : " << books[i]->getISBN() << endl;
        }
    }
    
    if(!found)
    {
        cout << "Book Not Found!" << endl;
    }
}

Library::~Library()
{
    for(int i = 0; i < bookCount; i++)
    {
        delete books[i];
    }
    delete[] books;
}