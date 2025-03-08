#include<iostream>
using namespace std;

class Person
{
    string name;
    int age;

    public:
        Person(string name, int age) : name(name), age(age) {}

        void displayDetails()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

class Teacher : virtual public Person
{
    protected:
    string subject;

    public:
        Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {} 

        void displayDetails()
        {
            Person::displayDetails();
            cout << "Subject: " << subject << endl;
        }
};

class Researcher : virtual public Person
{
    protected:
    string researchArea;

    public:
        Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

        void displayDetails()
        {
            Person::displayDetails();
            cout << "Research Area: " << researchArea << endl;
        }
};

class Professor : public Teacher, public Researcher
{
    int publications;

    public:
        Professor(string name, int age, string subject, string researchArea, int publications)
            : Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}


        void displayDetails()
        {
            Person::displayDetails();
            cout << "Subject : " << subject << endl;    
            cout << "Research Area : " << researchArea << endl;    
            cout << "Publications: " << publications << endl;
        }
};

int main()
{
    Professor prof("Shahid Ashraf", 50, "Maths", "Multi Variable Calculus", 5);
    prof.displayDetails();

    return 0;
}