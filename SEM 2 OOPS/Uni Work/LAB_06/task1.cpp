#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    float salary;

public:
    Employee(string name, float salary) : name(name), salary(salary) {}

    void displayDetails()
    {
        cout << "Name : " << name << endl;
        cout << "Salary : " << salary << endl;
    }
};

class Manager : public Employee
{
private:
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails()
    {
        Employee::displayDetails();
        cout << "Bonus : " << bonus << endl;
    }
};

int main()
{
    Manager m1("Ahmed", 500000.00, 25000.00);
    m1.displayDetails();
}