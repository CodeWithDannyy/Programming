#include<iostream>
using namespace std;

class Teacher;

class Student
{
    string name;
    float grades[3];
    
    public:
        Student(string name, double grade1, double grade2, double grade3) : name(name)
        {
            grades[0] = grade1;
            grades[1] = grade2;
            grades[2] = grade3;
        }

        friend class Teacher;
        friend float calculateAverageGrade(Student &student);
};

float calculateAverageGrade(Student &student)
{
    float sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += student.grades[i];
    }
    return sum/3;
}

class Teacher
{
    public:

    void updateGrade(Student& student, int index, float newGrade)
    {
        if(index >= 0 && index < 3)
        {
            student.grades[index] = newGrade;
            cout << "Grade Updated " << endl;
        }
        else
            cout << "Invalid Grade Update" << endl ;
    }

    void viewGrades(Student& student)
    {
        cout << "Grades of " << student.name << " : " <<endl;
        for(int i = 0; i < 3; i++)
        {
            cout << "Grade " << i+1 << ": " << student.grades[i] << endl;
        }
    }
};

int main()
{
    Student student("Danny", 93.5, 94.0, 90.0);
    Teacher teacher;

    teacher.viewGrades(student);
    teacher.updateGrade(student, 2, 92.0);

    teacher.viewGrades(student);

    double average = calculateAverageGrade(student);
    cout << "Average Grade : " << average << endl;
}