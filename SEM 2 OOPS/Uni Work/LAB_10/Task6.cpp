#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Inventory
{
    public:
        int itemID;
        char name[20];
};

int main()
{
    Inventory item1;
    item1.itemID = 101;
    strncpy(item1.name, "Mobile", sizeof(item1.name) - 1);
    item1.name[sizeof(item1.name) - 1] = '\0';

    ofstream outFile("Inventory.dat",ios::binary);
    if(!outFile)
    {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }
    outFile.write((char*)&item1, sizeof(item1));
    outFile.close();

    Inventory item2;
    ifstream inFile("Inventory.dat", ios::binary);
    if(!inFile)
    {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }
    inFile.read((char*)&item2, sizeof(item2));
    inFile.close();

    cout << "ID : " << item2.itemID << endl;
    cout << "Name : " << item2.name << endl;
}