#include<iostream>
using namespace std;

typedef struct 
{
    string name;
    int rollNumber;
    int marks[5];
}Student;

int main()
{
    int numOfStudents;

    cout << "Enter Number of Students : ";
    cin >> numOfStudents;

    Student students[numOfStudents];


}