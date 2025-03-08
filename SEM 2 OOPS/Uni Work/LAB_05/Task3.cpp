#include<iostream>
using namespace std;

class Professor
{
    private:
        string name;
        int age;
        double salary;
        string department;
        
    public:
        Professor() : name("Unknown"), age(0), salary(0.0), department("Unknown") {}

        Professor(string name, int age, double salary, string department) : name(name), age(age), salary(salary), department(department) {}

        void displayDetails()
        {
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "Salary : $" << salary << endl;
            cout << "Department : " << department << endl;
        }

};

class University
{
    private:
        string universityName;
        Professor **professors;
        int professorCount;
        int maxProfessors;
        
    public:
        University() : universityName("Unknown"), professorCount(0), maxProfessors(0)
        {
            professors = new Professor*[maxProfessors];
        }

        University(string universityName, int maxProfessors) : universityName(universityName), professorCount(0), maxProfessors(maxProfessors)
        {
            professors = new Professor*[maxProfessors];
        }

        void addProfessor(string name, int age, double salary, string department)
        {
            if(professorCount < maxProfessors)
            {
                professors[professorCount++] = new Professor(name, age, salary, department);
            }
            else
                cout << "Cannot add more professors" << endl;
        }

        void displayUniversityDetails()
        {
            cout << "University Name : " << universityName << endl;
            cout << "Number of Professors : " << professorCount << endl;
            cout << "Professors : " << endl;
            for(int i = 0; i < professorCount; i++)
            {
                cout << "Professor " << i+1 << ":" << endl;
                professors[i]->displayDetails();
                cout << endl;
            }
        }

        ~University()
        {
            for(int i = 0; i < professorCount; i++)
            {
                delete professors[i];
            }
            delete[] professors;
        }

};

int main()
{
    University university("FAST University", 5);
    university.addProfessor("John Arthur", 51, 100000, "CS");
    university.addProfessor("Jane Doe", 49, 80000, "Physics");
    university.addProfessor("Michael Smith", 52, 95000, "Mathematics");

    university.displayUniversityDetails();

    return 0;
}