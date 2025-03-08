#include<iostream>
using namespace std;

class Employee
{
    private:
        string employeeName;
        int employeeID;
        static int nextEmployeeID;
        const float MAX_SALARY = 50000.0;
        float salary; 

    public:
        Employee()
        {
            employeeID = generateEmployeeID();
        }
        static int generateEmployeeID()
        {
            return nextEmployeeID++;
        }

        void setName(const string& name)
        {
            employeeName = name;
        }
        void setSalary(float salary)
        {
            if(salary > MAX_SALARY)
            {
                cout << "Salary cannot be more than " << MAX_SALARY << endl;
                this->salary = MAX_SALARY;
            }
            else
                this->salary = salary;
        }

        void displayEmployeeInfo()
        {
            cout << "Employee Name: " << employeeName << endl;
            cout << "Employee ID: " << employeeID<< endl;
            cout << "Salary: $" << salary << endl;
        }

};

int Employee::nextEmployeeID = 1000;

int main()
{
    Employee e1;
    e1.setName("John Doe");
    e1.setSalary(40000.0);
    e1.displayEmployeeInfo();

    Employee e2;
    e2.setName("Jane Smith");
    e2.setSalary(80000.0);
    e2.displayEmployeeInfo();
}