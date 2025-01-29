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
    bool found = false;
    int totalValue = 0;

    do
    {
        cout << "-------- Inventory Management System --------" << endl;
        cout << "1. Add Product"<<endl;
        cout << "2. Remove Product "<<endl;
        cout << "3. Update Product "<< endl;
        cout << "4. Display Total Value of the inventory"<<endl;
        cout << "5. Display All Products in the inventory"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice (1-6) : ";
        cin >> choice;

        switch (choice)
        {
            case 1: {
                Product* temp = new Product[productCount + 1];
                for (int i = 0; i < productCount; i++)
                    temp[i] = products[i];
                
                delete[] products; 
                products = temp;   

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
                }
            case 2:
                if(productCount == 0)
                {
                    cout <<"There are no products to remove";
                    break;
                }
                int productID;
                cout << "Enter the ID of the product you want to remove : ";
                cin >> productID;

                for(int i = 0; i < productCount; i++)
                {
                    if(products[i].productID == productID)
                    {
                        found = true;
                        for(int j = 0; j < productCount - 1; j++)
                        {
                            products[j] = products[j+1];
                        }
                        productCount--;

                        Product *temp = new Product[productCount];
                        for(int i = 0; i < productCount; i++)   
                            temp[i] = products[i];
                        delete[] products;
                        products =temp;

                        cout<<"Product Removed"<<endl;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "Invalid Product ID"<<endl;
                }
                break;

            case 3:
                if(productCount == 0)
                {
                    cout << "There are no products to update" << endl;
                    break;
                }

                cout << "Enter the ID of the product you want to update : ";
                cin >> productID;

                for(int i = 0 ; i < productCount; i++)
                {
                    if(products[i].productID == productID)
                    {
                        found = true;
                        cout << "Updating Product ID: " << productID << endl;

                        cout << "Enter New Product Name (current: " << products[i].productName << "): ";
                        cin.ignore();
                        getline(cin, products[i].productName);
                        

                        cout << "Enter New Quantity (current: " << products[i].quantity << "): ";
                        cin >> products[i].quantity;

                        cout << "Enter New Product Price (current: " << products[i].price << "): ";
                        cin >> products[i].price;

                        cout << "Product updated successfully!" << endl;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "Invalid Product ID"<<endl;
                }
                break;

            case 4:
                cout << "Total value of the inventory : ";
                totalValue = 0;
                for(int i = 0; i < productCount; i++)
                {
                    totalValue += (products[i].price * products[i].quantity);
                }
                cout << totalValue << endl;
                break;
            
            case 5:
                if(productCount == 0)
                {
                    cout << "No Products in the inventory ";
                    break;
                }
                cout << "All the products in the inventory "<<endl;
                for(int i = 0; i < productCount; i++)
                {
                    cout << "Product "<<i+1<<endl;
                    cout << "Product ID : "<< products[i].productID<<endl;
                    cout << "Product Name : "<< products[i].productName << endl;
                    cout << "Product Price : " << products[i].price << endl;
                    cout << "Product Quantity : " << products[i].quantity << endl;
                }
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