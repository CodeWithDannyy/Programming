#include<iostream>
#include<string>
using namespace std;

class GroceryStore {
    private:
        string items[10];   
        float prices[10];  
               

    public:
        int itemCount;
        void addItem(string item, float price) {
            if(itemCount < 10) {
                items[itemCount] = item;
                prices[itemCount] = price;
                itemCount++;
            } else {
                cout << "Inventory is full" << endl;
            }
        }

        void updatePrice(string item, float newPrice) {
            for(int i = 0; i < itemCount; i++) {
                if(items[i] == item) {
                    prices[i] = newPrice;
                    cout << "Price updated for " << item << endl;
                    return;
                }
            }
            cout << "Item not found" << endl;
        }

        void viewInventory() {
            cout << "Inventory List: " << endl;
            for(int i = 0; i < itemCount; i++) {
                cout << items[i] << " , " << prices[i] << " Rs" << endl;
            }
        }

        void generateReceipt() {
            float total = 0;
            cout << "Receipt: " << endl;
            for(int i = 0; i < itemCount; i++) {
                cout << items[i] << " , " << prices[i] << " Rs" << endl;
                total += prices[i];
            }
            cout << "Total: " << total << " Rs" << endl;
        }
};

int main() {
    GroceryStore store;
    store.itemCount = 0;
    int choice, exit = 1;
    string item;
    float price, newPrice;

    do {
        cout << "\nGrocery Store Menu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Update Price" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. Generate Receipt" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, item);

                
                cout << "Enter item price: ";
                cin >> price;
                store.addItem(item, price);
                break;
            case 2:
                cout << "Enter item name to update: ";
                cin.ignore();
                getline(cin, item);
                cout << "Enter new price: ";
                cin >> newPrice;
                store.updatePrice(item, newPrice);
                break;
                
            case 3:
                store.viewInventory();
                break;
            case 4:
                store.generateReceipt();
                break;
            case 5:
                cout << "Exiting program." << endl;
                exit = 0;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(exit);

    return 0;
}
