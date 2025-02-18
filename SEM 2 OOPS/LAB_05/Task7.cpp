#include<iostream>
using namespace std;

class Product
{
    private:
        int ID;
        string name;
        double price;

    public:
        Product() {} 
        Product(int ID, string name, double price) : ID(ID), name(name), price(price) {}

        int getID() const { return ID; }
        string getName() const { return name; }
        double getPrice() const { return price; }

        void displayProduct()
        {
            cout << "ID: " << ID << endl;
            cout << "Name: " << name << endl;
            cout << "Price: $" << price << endl;
        }
};  

class Inventory
{
    private:
        Product *products;
        int productsCount;
        int maxProducts;
    
    public:
        Inventory(int maxProducts) : productsCount(0), maxProducts(maxProducts)
        {
            products = new Product[maxProducts];
        }

        void addProduct(Product *product)
        {
            if(productsCount < maxProducts)
            {
                products[productsCount++] = *product;
            }
            else
            {
                cout << "Inventory is full" << endl;
            }
        }

        void sortProductsInAscendingOrder()
        {
            for(int i = 0; i < productsCount - 1; i++)
            {
                for(int j = 0; j < productsCount - i - 1; j++)
                {
                    if(products[j].getPrice() > products[j+1].getPrice())
                    {
                        Product temp = products[j];
                        products[j] = products[j+1];
                        products[j+1] = temp;
                    }
                }
            }
        }

        void displayInventory()
        {
            cout << "Inventory Products : " << endl;
            for(int i = 0; i < productsCount; i++)
            {
                products[i].displayProduct();
                cout << endl;
            }
        }

        void searchProductByName(string productName)
        {
            for(int i = 0; i < productsCount; i++)
            {
                if(products[i].getName() == productName)
                {
                    products[i].displayProduct();
                    return;
                }
            }
            cout << "Product not found" << endl;
        }
        
        ~Inventory()
        {
            delete[] products;
        }
};

int main()
{
    Inventory inventory(3);
    
    Product product1(1, "Apple", 1.5);
    Product product2(2, "Banana", 0.75);
    Product product3(3, "Mango", 1.25);

    inventory.addProduct(&product1);
    inventory.addProduct(&product2);
    inventory.addProduct(&product3);

    cout << "Inventory : " << endl;
    inventory.displayInventory();

    inventory.sortProductsInAscendingOrder();

    cout << "\nSorted Inventory : " << endl;
    inventory.displayInventory();

    cout << "\nSearching Product By Name : " <<endl;
    inventory.searchProductByName("Banana");

    return 0;

}
