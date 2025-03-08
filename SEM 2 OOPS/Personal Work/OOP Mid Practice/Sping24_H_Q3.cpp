#include<iostream>
using namespace std;

class Employee
{
    private:
        string name;
        int age;
        string joiningDate;

    public:
        Employee(string name, int age, string joiningDate) : name(name), age(age), joiningDate(joiningDate) {}

        void displayDetails()
        {
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "Joining Date : " << joiningDate << endl;
        }
};

class Developer : virtual public Employee
{
    protected:
        string devRole;
    
    public:
        Developer(string name, int age, string joiningDate, string devRole) : Employee(name, age, joiningDate), devRole(devRole) {}
};

class Debugger : virtual public Employee
{
    protected:
        string dbgRole;

    public:
        Debugger(string name, int age, string joiningDate, string dbgRole) : Employee(name, age, joiningDate), dbgRole(dbgRole) {}
};

class TeamLead : public Developer, public Debugger
{
    public:
        TeamLead(string name, int age, string joiningDate, string devRole, string dbgRole) : Employee(name, age, joiningDate), Developer(name, age, joiningDate, devRole), Debugger(name, age, joiningDate, dbgRole) {}

        void displayDetails()
        {
            Employee::displayDetails();
            cout << "Developer Role : " << devRole << endl;
            cout << "Debugger Role : " << dbgRole << endl;
        }
};

int main()
{
    TeamLead teamLead("John Doe", 30, "2021-01-01", "Senior Developer", "Senior Debugger");
    teamLead.displayDetails();
}