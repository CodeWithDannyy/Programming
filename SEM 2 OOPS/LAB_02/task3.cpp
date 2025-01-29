#include<iostream>
using namespace std;

typedef struct
{
    int employeeID;
    string name;
    string department;
    int salary;
} Employee;

int main()
{
    int numOfEmployees;
    cout << "Enter Number of employees : ";
    cin >> numOfEmployees;
    Employee *emps;
    emps = new Employee[numOfEmployees];
    for(int i = 0; i < numOfEmployees; i++)
    {
        cout << "Enter Information for Employee "<<i+1<<endl;

        cout << "Enter Employee ID : ";
        cin >> emps[i].employeeID;
        cin.ignore();

        cout << "Enter Employee Name : ";
        getline(cin, emps[i].name);

        cout << "Enter Employee Department: ";
        getline(cin, emps[i].department);

        cout << "Enter Salary : ";
        cin >> emps[i].salary;
        cin.ignore();
    }

    cout << "\nEmployee Information";
    for(int i = 0; i < numOfEmployees; i++)
    {
        cout << "Information for Employee "<<i+1<<endl;
        cout << "Employee ID : "<<emps[i].employeeID<<endl;
        cout << "Employee Name : "<<emps[i].name<<endl;
        cout << "Employee Department : "<<emps[i].department<<endl;
        cout << "Employee Salary : "<< emps[i].salary<<endl;
    }

    int empID;
    cout << "\nEnter Employee ID to search for Employee Information : ";
    cin >> empID;

    bool found = false;
    for(int i = 0; i < numOfEmployees; i++)
    {
        if(empID == emps[i].employeeID)
        {
            found = true;
            cout << "Employee ID : "<<emps[i].employeeID<<endl;
            cout << "Employee Name : "<<emps[i].name<<endl;
            cout << "Employee Department : "<<emps[i].department<<endl;
            cout << "Employee Salary : "<< emps[i].salary<<endl;
            break;
        }
    }

    if(!found)
    {
        cout << "\n Employee Not Found."<<endl;
    }

    delete[] emps;

}