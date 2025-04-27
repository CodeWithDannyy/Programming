#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream inputFile("data_records.txt");

    if (!inputFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    inputFile.seekg(20, ios::beg);  

    string record;
    getline(inputFile, record);

    cout << "Third Record: " << record << endl;

    inputFile.close();

    return 0;
}
