#include<iostream>
using namespace std;

typedef struct 
{
    string name;
    int rollNumber;
    float marks;
}Student;

int main()
{
    int studentCount = 0;
    Student *students = nullptr;
    int choice, exit = 1;

    do
    {
        cout << "-------- Student Record Management System --------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Student with Highest Marks" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4) : ";
        cin >> choice;

        switch (choice)
        {
            case 1: {
                Student* temp = new Student[studentCount + 1];
                for (int i = 0; i < studentCount; i++)
                    temp[i] = students[i];
                delete[] students;
                students = temp;

                cout << "Enter information for Student " << studentCount + 1 << endl;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, students[studentCount].name);

                cout << "Enter Roll Number: ";
                cin >> students[studentCount].rollNumber;
                cin.ignore();

                cout << "Enter Marks: ";
                cin >> students[studentCount].marks;
                cin.ignore();

                studentCount++;
                break;
            }

            case 2: {
                if (studentCount == 0)
                {
                    cout << "No students in the records!" << endl;
                    break;
                }

                int highestMarksIndex = 0;
                for (int i = 1; i < studentCount; i++)
                {
                    if (students[i].marks > students[highestMarksIndex].marks)
                    {
                        highestMarksIndex = i;
                    }
                }

                cout << "Student with the Highest Marks: " << endl;
                cout << "Name: " << students[highestMarksIndex].name << endl;
                cout << "Roll Number: " << students[highestMarksIndex].rollNumber << endl;
                cout << "Marks: " << students[highestMarksIndex].marks << endl;
                break;
            }

            case 3: {
                if (studentCount == 0)
                {
                    cout << "No students in the records!" << endl;
                    break;
                }

                cout << "All the students in the records: " << endl;
                for (int i = 0; i < studentCount; i++)
                {
                    cout << "Student " << i + 1 << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Roll Number: " << students[i].rollNumber << endl;
                    cout << "Marks: " << students[i].marks << endl;
                }
                break;
            }

            case 4:
                exit = 0;
                break;

            default:
                cout << "Wrong Choice" << endl;
                break;
        }
    } while (exit);

    delete[] students;
    return 0;
}
