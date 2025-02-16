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

        double CalculatingFinalPrice(int quantity) 
        {
            return applyDiscount(quantity) * quantity;
        }

        void purchase(int quantity)
        {
            if(quantity > stock)
            {
                cout << "Error! Stock Size is " << stock << endl;  
                return;
            }
            
            double priceAfterDiscount = applyDiscount(quantity);
            double totalPrice = CalculatingFinalPrice(quantity);
            stock -= quantity;
            cout << quantity << " books purchased with each book being $" << priceAfterDiscount << endl;
            cout << "Total Price of " << quantity <<" Books (Title : " << *title << ") : " << totalPrice << endl;
            
            
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
    Book book1("Learning C++", 50.00, 30);

    book1.purchase(26);
    
    return 0;
}
