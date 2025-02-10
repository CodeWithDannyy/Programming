#include<iostream>
using namespace std;

class Book
{
    private:
        string *title;
        double price;
        int stock;

    public:
        Book()
        {
            title = new string("Unknown");
            price = 0.0;
            stock = 30;
        }

        Book(string title, double price, int stock)
        {
            this->title = new string(title); 
            this->price =  price;
            this->stock = stock;
        } 
        
        Book(const Book &obj)
        {
            title = new string(*obj.title);
            price = obj.price;
            stock = obj.stock;
        }

        void updateBookDetails(string title, double price, int stock)
        {
            *this->title = title;
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
            cout << "Title : " << *title << endl;
            cout << "Price : " << price << endl;
            cout << "Stock : " << stock << endl;
        }

        ~Book()
        {
            delete title;
            cout << "Destructor Called" << endl; 
        }

};

int main()
{
    Book book1;
    Book book2 = book1;

    cout << "Updating Book 1 Details " << endl;
    book1.updateBookDetails("Pride and Prejudice",50.00,15);

    cout << "Book 1 Details" << endl;
    book1.display();

    cout << "Book 2 Details " << endl;
    book2.display();
    
    return 0;
}
