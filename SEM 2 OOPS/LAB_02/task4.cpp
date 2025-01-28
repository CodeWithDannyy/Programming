#include<iostream>
using namespace std;

typedef struct 
{
    string name;
    int rollNumber;
    int marks[5];
    float average;
    string grade;
}Student;

string grade(float average){
    if(average >= 86)
            return "A";
        else if(average >= 82)
            return "A-";
        else if(average >= 78)
            return "B+";
        else if(average >= 74)
            return "B";
        else if(average >= 70)
            return "B-";
        else if(average >= 66)
            return "C+";
        else if(average >= 62)
            return "C";
        else if(average >= 58)
            return "C-";
        else if(average >= 54)
            return "D+";
        else if(average >= 50)
            return "D";
        else
            return "F";
}
int main()
{
    int numOfStudents;

    cout << "Enter Number of Students : ";
    cin >> numOfStudents;

    Student *students = new Student[numOfStudents];

    for(int i = 0; i < numOfStudents; i++)
    {
        cout << "Enter Information for Student "<< i+1 << endl;

        cout << "Enter Name : ";
        cin.ignore();
        getline(cin,students[i].name);

        cout << "Enter Roll Number : ";
        cin >> students[i].rollNumber;

        cout << "Enter Marks for 5 subjects "<<endl;
        int total = 0;
        float avg = 0.0;
        for(int j = 0; j < 5; j++)
        {
            cout << "Enter Marks for subject " << j+1 <<" : ";
            cin >> students[i].marks[j];
            total += students[i].marks[j];
        }
        students[i].average = (float)total/5;
        students[i].grade = grade(students[i].average);
        
        cout << endl;
    }

    cout << "Displaying Student Information";
    for(int i = 0; i < numOfStudents; i++)
    {
        cout << "Information for Student "<<i+1<<endl;

        cout << "Name : " << students[i].name;
        cout << "Roll Number : "<< students[i].rollNumber << endl;
        cout << "Average : "<< students[i].average << endl;
        cout << "Grade : "<< students[i].grade << endl;
    }

    delete[] students;

    return 0;
}