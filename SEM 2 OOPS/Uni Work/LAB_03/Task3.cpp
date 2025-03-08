#include<iostream>
using namespace std;

class Planner
{
    private:
        string tasks[12][31];

        bool ValidateDate(int day, int month)
        {
            if(month < 1 || month > 12 || day < 1 || day > 31)
                return false;
            if((month == 2 && day > 28) || (month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
                return false;
            return true;
        }
    public:
        void initializeTasksArray()
        {
            for(int i = 0; i < 12; i++)
            {
                for(int j = 0; j < 31; j++)
                {
                    tasks[i][j] = "";
                }
            }
        }

        void addTask(int day, int month, string task)
        {
            if(ValidateDate(day, month))
            {
                tasks[month - 1][day - 1] = task;
                cout << "Task Added Sucessfully" << endl;
            } 
            else
            {
                cout << "Invalid Date!" << endl;
            }
        }

        void removeTask(int day, int month)
        {
            if(ValidateDate(month,day))
            {
                if(tasks[month - 1][day - 1] != "")
                {
                    tasks[month - 1][day - 1] = "";
                    cout << "Task Removed Sucessfully" << endl; 
                }
                else
                    cout << "No Task on this day" << endl;
            }
            else
            {
                cout << "Invalid Date!" << endl;
            }
        }

        void displayTasks()
        {   
            bool found = false;
            cout << "Tasks Scheduled For the year" << endl;
            for(int i = 0; i < 12; i++)
            {
                for(int j = 0; j < 31; j++)
                {
                    if(ValidateDate(i + 1 , j + 1) && tasks[i][j] != "")
                    {
                        cout << "Task on Month "<< i+1 << ", Day "<< j+1 << " is "<< tasks[i][j] << endl;
                        found = true;
                    }
                }
            }
            if(!found)
            {
                cout << "No tasks Scheduled For the year." << endl;
            }
        }


};

int main()
{
    Planner planner;
    planner.initializeTasksArray();
    int exit = 1;
    int choice;
    int day,month;
    string task;
    do
    {
        cout << "---- Task Management System ----" << endl;
        cout << "1. Add Tasks" << endl;
        cout << "2. Remove Tasks" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Select Options 1 - 4 : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Adding Task " << endl;
            cout << "Enter Day : ";
            cin >> day;
            cout << "Enter Month : ";
            cin >> month;

            cin.ignore();

            cout << "Enter Task : ";
            getline(cin, task);
            planner.addTask(day, month, task);
            break;
        
        case 2:
            cout << "Removing Task " << endl;
            cout << "Enter Day : ";
            cin >> day;
            cout << "Enter Month : ";
            cin >> month;
            planner.removeTask(day, month);
            break;

        case 3:
            planner.displayTasks();
            break;

        case 4:
            exit = 0;
            break;
        
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (exit);
    
    return 0;
}