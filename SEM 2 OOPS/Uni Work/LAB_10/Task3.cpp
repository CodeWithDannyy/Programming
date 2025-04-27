#include<iostream>
#include<fstream>
#include<sstream>
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
    string type,id,name,extraData,certification;
    string line;
    int i = 0;
    int year;
    while(getline(inpFile, line))
    {
        cout << "Car " << i+1 << ":" << endl;
        istringstream iss(line);
        getline(iss,type,',');
        getline(iss,id,',');
        getline(iss,name,',');
        getline(iss,line,',');
        year = stoi(line);
        getline(iss,extraData,',');
        getline(iss,certification,',');

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Extra Data: " << extraData << endl;
        cout << "Certification: " << certification << endl;
        cout << "---------------" << endl;
        i++;
    }

    inpFile.close();
}