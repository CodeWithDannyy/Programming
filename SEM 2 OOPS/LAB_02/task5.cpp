#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char *str1,*str2;
    str1 = new char[100];
    str2 = new char[100];

    cout << "Input String 1 : ";
    cin.ignore();
    getline(cin, str1); 
}