#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outFile("config.txt");
    if(!outFile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    outFile << "AAAAABBBBBCCCCC" << endl;
    outFile.close();

    fstream file("config.txt", ios::in|ios::out);
    if(!file)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    file.seekp(6);
    file << "XXXXX";
    file.close();
}