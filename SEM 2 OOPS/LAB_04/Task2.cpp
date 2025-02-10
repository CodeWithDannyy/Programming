#include<iostream>
using namespace std;

class Book
{
    private:
        string title;
        double price;
        int stock;

    public:
        int *ptr;
        Book()
        {
            title = "Unknown";
            price = 0.0;
            stock = 30;
        }

        Book(string title, double price, int stock)
        {
            this->title = title ; 
            this->price =  price;
            this->stock = stock;
        } 

        void updateBookDetails(string title, double price, int stock)
        {
            this->title = title;
            this->price = price;
            this->stock = stock;
        }

        double applyDiscount(int quantity) 
        {
            if(quantity > 10)
            {
                return price * 0.9;
            }
            else if (quantity > 5)
            {
                return price * 0.95;
            }
            return price;
        }

        void purchase(int quantity)
        {
            if(quantity > stock)
            {
                cout << "Error! Stock Size is " << stock << endl;  
                return;
            }
            
            double priceAfterDiscount = applyDiscount(quantity);
            stock -= quantity;
            cout << quantity << " books purchased with each book being $" << priceAfterDiscount << endl;
            
            
            if(stock < 5)
            {
                cout << "Low Stock!! Only " << stock << " books Available" << endl;
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
    Book book2("No Longer Human", 30.00, 10);

    cout << "Book 1 Details " << endl;
    book1.display();
    cout<< "Book 2 Details " << endl;
    book2.display();

    book2.purchase(6);

    book2.purchase(5);

    book2.display();

    return 0;
}