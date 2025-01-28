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
    Employee *emps;
    emps = new Employee[3];
    // GAAND MARA ALI RAZA (frend hai)
    for(int i = 0; i < 3; i++)
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
    for(int i = 0; i < 3; i++)
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
    for(int i = 0; i < 3; i++)
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