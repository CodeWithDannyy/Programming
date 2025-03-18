#include<iostream>
using namespace std;

class Person
{
    protected:
        string name;
        string id;
        string address;
        string phoneNumber;
        string email;
    
    public:
        Person(string name, string id, string address, string phoneNumber, string email)
            : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {}

        void updateInfo(string address, string phoneNumber, string email)
        {
            this->address = address;
            this->phoneNumber = phoneNumber;
            this->email = email;
        }

        virtual void displayInfo()
        {
            cout << "Name : " << name << endl;
            cout << "ID : " << id << endl;
            cout << "Adress : " << address << endl;
            cout << "Phone Number : " << phoneNumber << endl;
            cout << "Email : " << email << endl;
        }
};

class Student : public Person
{
    string coursesEnrolled[5];
    double gpa;
    int enrollmentYear;

    public:
        Student(string name, string id, string address, string phoneNumber, string email, double gpa, int enrollmentYear, string coursesEnrolled[])
            : Person(name, id, address, phoneNumber, email), gpa(gpa), enrollmentYear(enrollmentYear)
        {
            for(int i = 0; i < 5; i++)
            {
                this->coursesEnrolled[i] = coursesEnrolled[i];
            }
        }   

        void displayInfo()
        {
            Person::displayInfo();
            cout << "GPA : " << gpa << endl;
            cout << "Enrollment Year : " << enrollmentYear << endl;
            cout << "Courses Enrolled" << endl;
            for(int i = 0; i < 5; i++)
            {
                cout << "Course " << i+1 << " : " << coursesEnrolled[i] <<endl;
            }
        }
};

class Professor : public Person
{
    string department;
    string coursesTaught[3];
    double salary;

    public:
        Professor(string name, string id, string address, string phoneNumber, string email, string department, double salary, string coursesTaught[])
            : Person(name, id, address, phoneNumber, email), department(department),  salary(salary)
        {
            for(int i = 0; i < 3; i++)
            {
                this->coursesTaught[i] = coursesTaught[i];
            }
        }

        void displayInfo()
        {
            Person::displayInfo();
            cout << "Department : " << department << endl;
            cout << "Salary : " << salary << endl;
            cout << "Courses Taught" << endl;
            for(int i = 0; i < 3; i++)
            {
                cout << "Course " << i+1 << " : " << coursesTaught[i] <<endl;
            }
        }
};

class Staff : public Person {

    string department;
    string position;
    double salary;
    
    public:
        Staff(string name, string id, string address, string phoneNumber, string email, string department, string position, double salary)
            : Person(name, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}
    
        void displayInfo()
        {
            Person::displayInfo();
            cout << "Department : " << department << endl;
            cout << "Position : " << position << endl;
            cout << "Salary : " << salary << endl;
        }
};




class Course
{
    string courseID;
    string courseName;
    string schedule;
    int credits;
    Professor *instructor;
    Student* students[10];
    int studentCount;

    public:
        Course(string courseID, string courseName, string schedule, int credits)
            : courseID(courseID), courseName(courseName), schedule(schedule), credits(credits), studentCount(0) {}

        void registerStudent(Student *student)
        {
            if(studentCount < 10)
            {
                students[studentCount++] = student;
                cout << "Student Enrolled" << endl;
            }
            else
                cout << "Cannot add more student" << endl;
        }

        void calculateGrade()
        {
            cout << "Calculating grades..." << endl;
        }
};

int main()
{
    string studentCourses[] = {"CS101", "MATH102", "PHYS103", "ENG104", "HIST105"};
    Student student("Danny", "24K-0671", "Street 1", "+92001000111", "danny@gmail.com", 3.9, 2024, studentCourses);

    string professorCourses[] = {"CS101", "CS202", "CS303"};
    Professor professor("James", "10001", "Street 2", "+920000000", "james@gmail.com", "Computer Science", 400000.0, professorCourses);

    Staff staff("John Doe", "301", "Admin Block", "555-1234", "johndoe@example.com", "Administration", "Manager", 60000);

    Person* person[3];
    person[0] = &student;
    person[1] = &professor;
    person[2] = &staff;

    for(int i = 0; i < 3; i++)
    {
        person[i]->displayInfo();
        cout<<"------------"<<endl;
    }

    Course c1("CS1001", "Object Oriented Programming", "Tue-Thur-Fri 10:00 - 11:00 AM", 3);

    c1.registerStudent(&student);
}