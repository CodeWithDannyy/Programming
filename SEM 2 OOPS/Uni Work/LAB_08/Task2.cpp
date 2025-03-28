#include<iostream>
using namespace std;

class Librarian;

class Book
{
    string title;
    double price;

    public:
        Book(string title, double price) : title(title) , price(price) {}

        friend class Librarian;
};

class Librarian
{
    public:
    
    void display(const Book& book) const
    {
        cout << "Title : " << book.title << endl;
        cout << "Price : " << book.price << endl;
    }

    void discount(Book& book, double amount)
    {
        book.price -= amount;
        cout << "Discounted Price : " << book.price << endl;
    }
};

int main()
{
    Book book("C++ Programming", 100.0);

    Librarian lib;

    lib.display(book);
    lib.discount(book, 20.0);
}