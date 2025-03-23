#include<iostream>
using namespace std;

int hashPassword(string password)
{
    int hash = 5381;
    for(int i = 0; i < password.length(); i++)
    {
        hash = hash * 33 + password[i];
    }
    return hash;
}

class User
{
    protected:
        string name;
        string email;
        int ID;
        int hashedPassword;
        string permissions[5];
        int permCount;

    public:
        User(string name, string email, int ID, string hashedPassword, string permissions[], int permCount)
            : name(name), email(email), ID(ID), hashedPassword(hashPassword(hashedPassword)), permCount(permCount)
        {
            for(int i = 0; i < permCount; i++)
            {
                this->permissions[i] = permissions[i];
            }
        }

        bool authenticate()
        {
            string inputPassword;
            cout << "Enter password for " << name << ": ";
            cin >> inputPassword;
            return hashPassword(inputPassword) == hashedPassword;
        }

        bool hasPermission(string action)
        {
            for (int i = 0; i < permCount; i++)
            {
                if (permissions[i] == action)
                {
                    return true;
                }
            }
            return false;
        }

        virtual void display()
        {
            cout << "Name : " << name << endl;
            cout << "ID : " << ID << endl;
            cout << "Email : " << email << endl;
            cout << "Permissions : " << endl;
            for(int i = 0; i < permCount; i++)
            {
                cout << permissions[i] << endl;
            }
        }

        void accessLab()
        {
            bool labAccess = false;
            for(int i = 0; i < permCount; i++)
            {
                if(permissions[i] == "fullLabAccess")
                {
                    labAccess = true;
                    break;
                }
            }
            cout << name << (labAccess ? " has full access to lab " : "does not have full access to lab") << endl;
        }

        string getName() const { return name; }
};

class Student : public User
{
    protected:
        int assignments[5];
    
    public:
        Student(string name, string email, int ID, string hashedPassword)
            : User(name, email, ID, hashedPassword, (string[]){"submitAssignment"}, 1)
        {
            for(int i = 0; i < 5; i++)
                assignments[i] = 0;
        }

        void submitAssignmnet(int assignmentNumber)
        {
            if((assignmentNumber - 1) >= 0 && (assignmentNumber - 1) < 5)
                assignments[(assignmentNumber - 1)] = 1;
        }

        void display()
        {
            User::display();
            cout << "Assignments: ";
            for(int i = 0; i < 5; i++)
            {
                cout << assignments[i] << endl;
            }
        }
};

class TA : public Student
{
    Student* students[10];
    string projects[2];
    int projectCount;
    int studentCount;

    public:
        TA(string name, string email, int ID, string hashedPassword)
            : Student(name, email, ID, hashedPassword), studentCount(0), projectCount(0)
        {
            string permList[] = {"viewProjects", "manageStudents"};
            this->permCount = 2;
            for (int i = 0; i < permCount; i++)
            {
                this->permissions[i] = permList[i];
            }
        }

        void assignStudent(Student* s)
        {
            if(studentCount < 10)
            {
                students[studentCount++] = s;
            }
            else
                cout << "Cannot add more students" << endl;
        }

        void addProject(string projectName)
        {
            if(projectCount < 2)
            {
                projects[projectCount++] = projectName;
            }
            else
                cout << "Cannot add more than 2 Projects" << endl;
        }

        void display()
        {
            User::display();

            cout << "Managing Students: " << endl;
            for (int i = 0; i < studentCount; i++) 
            {
                cout << students[i]->getName() << endl;
            }

            cout << "\nProjects: " << endl;
            for (int i = 0; i < projectCount; i++) 
            {
                cout << projects[i] << endl;
            }
        }
};

class Professor : public User
{
    public:
        Professor(string name, string email, int ID, string hashedPassword)
            : User(name, email, ID, hashedPassword, (string[]){"assignProject", "fullLabAccess"}, 2) { }

        void assignProjectToTa(TA* ta, string projectName)
        {
            ta->addProject(projectName);
        }

        void display()
        {
            User::display();
            cout << "Professor has access to lab and Assigns project to TA" << endl;
        }
};

void authenticateAndPerformAction(User *user, string action)
{
    if (user->authenticate())
    {
        cout << (user->hasPermission(action) ? "Action " + action + " performed successfully" : "Permission denied for " + action) << endl;
    }
    else
    {
        cout << "Authentication failed.\n";
    }
}

int main()
{
    Student student("Danny", "danny@gmail.com", 101, "student24");
    TA ta("Faris", "faris@gmail.com", 102, "TA123");
    Professor prof("Dr. Leonard", "leonard@gmail.com", 103, "prof987");

    student.submitAssignmnet(1);
    student.submitAssignmnet(2);

    cout << "\n==== STUDENT DETAILS ====" << endl;
    student.display();

    cout << "\n==== TA DETAILS ====" << endl;
    ta.display();

    cout << "\n==== PROFESSOR DETAILS ====" << endl;
    prof.display();

    authenticateAndPerformAction(&student, "submitAssignment");
    authenticateAndPerformAction(&ta, "viewProjects");
    authenticateAndPerformAction(&prof, "assignProject");

    prof.assignProjectToTa(&ta, "2D Platformer Game in C++");
    ta.assignStudent(&student);

    cout << "\n==== UPDATED TA DETAILS ====";
    ta.display();
    return 0;
}