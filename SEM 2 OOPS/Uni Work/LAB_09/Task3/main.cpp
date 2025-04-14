#include<iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
    Book book1("No Longer Human", "Osamu Dazai", "9780451524935");
    Book book2("Crime and Punishment", "Fyodor Dostoevsky", "9780316769488");
    Book book3("Metamorphisis", "Franz Kafka", "9780060935467");

    Library lib(5);

    lib.addBook(&book1);
    lib.addBook(&book2);
    lib.addBook(&book3);

    lib.removeBook(&book2);

    lib.searchBook("9780451524935");

    return 0;
}