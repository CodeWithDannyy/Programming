#include<iostream>
using namespace std;

class Book
{
    private:
        string title;
        double price;
        int stock;

    public:
        Book()
        {
            title = "Unknown";
            price = 0.0;
            stock = 30;
        }

        void updateBookDetails(string title, double price, int stock)
        {
            this->title = title;
            this->price = price;
            this->stock = stock;
        }

        void purchase(int quantity)
        {
            stock -= quantity;
            cout << quantity << " books purchased " << endl;

            if(stock < 5)
            {
                cout << "Low Stock!! Only " << stock << " Available" << endl;
            }
            
        }

        void display()
        {
            cout << "Title : " << title << endl;
            cout << "Price : " << price << endl;
            cout << "Stock : " << stock << endl;
        }

};

int main()
{
    Book book1;
    book1.display();

    book1.updateBookDetails("Crime and Punishment",50.0, 30);
    book1.display();

    book1.purchase(10);
    book1.display();

    return 0;
}