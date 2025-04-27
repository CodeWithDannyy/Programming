#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream inpFile("vehicles.txt");

    if(!inpFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    string type,id,name,year,extraData,certification;
    string line;
    while(getline(inpFile, line))
    {
        cout << line << endl;
        
    }

    inpFile.close();
}