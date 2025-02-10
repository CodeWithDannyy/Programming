#include<iostream>
using namespace std;

class Book
{
    private:
        static int bookCounter;
        int bookID;
        string *title;
        double price;
        int stock;

    public:
        Book() : bookID(++bookCounter) , title(new string("Unknown")) , price(0.0) , stock(30) {}

        Book(string title, double price, int stock) : bookID(++bookCounter) , title(new string(title)) , price(price) , stock(stock) {}
         
        Book(const Book &obj) : bookID(++bookCounter) , title(new string(*obj.title)) , price(obj.price) , stock(obj.stock) {}

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

        void showDetails()
        {
            cout << "Book ID : " << bookID << endl;
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

int Book :: bookCounter = 0;

int main()
{
    Book book1("Learning C++", 50.00, 30);
    Book book2("Learning C",30.00, 100);
    Book book3 = book2;

    book3.updateBookDetails("Learning Java", 20.00, 150);

    book1.showDetails();
    book2.showDetails();
    book3.showDetails();
    
    return 0;
}