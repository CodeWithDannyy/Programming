#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char *str1,*str2;
    str1 = new char[100];
    str2 = new char[100];

    cout << "Input String 1 : ";
    cin.getline(str1, 100); 


    cout << "Input String 2 : ";
    cin.getline(str2, 100);
    
    cout << "String 1 : " << str1 <<endl;
    cout << "String 2 : " << str2 << endl;
    cout << "Length of string 1 : " << strlen(str1) << endl;
    cout << "Length of string 2 : " << strlen(str2) << endl;


    if(strcmp(str1,str2) == 0)
        cout << "Both Strings are equal" << endl;
    else if (strcmp(str1 , str2) > 0)
        cout << "string 1 is greater than string 2" << endl;
    else
        cout << "String 2 is greater than string 1" << endl;

    
    strcat(str1,str2);
    cout << "String Concatenated : "<<str1<<endl;

    delete[] str1;
    delete[] str2;
}