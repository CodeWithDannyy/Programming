#include<iostream>
using namespace std;

typedef struct 
{
    int productID;
    string productName;
    int quantity;
    int price;
}Product;

int main()
{
    int productCount = 0;
    Product *products = new Product[productCount];
    int choice,exit = 1;

    do
    {
        cout << "-------- Inventory Management System --------" << endl;
        cout << "1. Add Product"<<endl;
        cout << "2. Remove Product "<<endl;
        cout << "3. Update Product "<< endl;
        cout << "4. Display Total Value of the inventory"<<endl;
        cout << "5. Display All Products in the inventory"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice (1-5) : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            products = new Product[productCount+1];
            cout << "Enter Information for Product "<< productCount+1 <<endl ;
            
                cout << "Enter Product ID : ";
                cin >> products[productCount].productID;

                cin.ignore();

                cout << "Enter Product Name : ";
                getline(cin, products[productCount].productName );

                cout << "Enter Quantity: ";
                cin >> products[productCount].quantity;
                cin.ignore();

                cout << "Enter Product Price : ";
                cin >> products[productCount].price;
                cin.ignore();

                productCount++;
            break;
        
        case 2:
            if(productCount == 0)
            {
                cout <<"There are no products to remove";
                return 0;
            }
            int productID;
            cout << "Enter the ID of the product you want to remove : ";
            cin >> productID;
            break;

        case 3:
            break;

        case 4:
            break;
        
        case 5:
            break;

        case 6:
            exit = 0;
            break;
        
        default:
            cout << "Wrong Choice"<<endl;
            break;
        }
    }while(exit);

    delete[] products;
}