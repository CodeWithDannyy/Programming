#include<iostream>
using namespace std;

class Student
{
    private:
        string studentID;
        string name;
        float cardBalance;
        int routeID;
        string stopName;
    
    public:
        Student() : studentID("XXK-0000"), name("Unknown"), cardBalance(0.0), routeID(0), stopName("Unknown") {}

        Student(string studentID, string name, float cardBalance, int routeID, string stopName) : studentID(studentID), name(name), cardBalance(cardBalance), routeID(routeID), stopName(stopName) {}

        void payFee(float amount)
        {
            if(amount > 0.0)
            {
                cardBalance += amount;
                cout << "Amount added to card. Card Balance : " << cardBalance << endl;
            }
            else
                cout << "Invalid Amount " << endl;
        }

        bool canBoard() {return cardBalance > 0.0;}

        void assignStop(string stop) {stopName = stop; }

        string getStopName() const {return stopName;}

        string getStudentID() const {return studentID;}

        string getStudentIDName() const {return name ; }

        int getRouteID() const {return routeID;}

        void displayStudent()
        {
            cout << "Student ID : " << studentID << endl;
            cout << "Name : " << name << endl;
            cout << "Card Balance : " << cardBalance << endl;
            cout << "Route ID : " << routeID << endl;
            cout << "Stop Name : " << stopName << endl;
        }
};

class Route
{
    private:
        string routeName;
        string *stops;
        int stopCount;
        int maxStops;
    
    public:
        Route() : routeName("Unknown") , stopCount(0), maxStops(0) 
        {
            stops = new string[maxStops];
        }

        Route(string routeName, int maxStops) : routeName(routeName), stopCount(0), maxStops(maxStops)
        {
            stops = new string[maxStops];
        }

        void addStop(string stop)
        {
            if(stopCount < maxStops)
            {
                stops[stopCount++] = stop;
            }
            else
            {
                cout << "Can't Add more stops" << endl;
            }
        }

        void displayStops()
        {
            cout << "Route Name : " << routeName << endl;
            cout << "Number of Stops : " << stopCount << endl;

            cout << "Stops : " << endl;
            for(int i = 0; i < stopCount; i++)
            {
                cout << "Stop " << i+1 << " : " << stops[i] << endl;
            }
        }

        ~Route() 
        {
            delete[] stops;
        }
};

class Bus
{
    private:
        int busID;
        Route *routes;

    public:
        Bus(int busID, Route *routes) : busID(busID), routes(routes) {}
        
        void recordAttendance(Student *student)
        {
            if(student->canBoard())
            {
                cout <<  student->getStudentID() << " "<< student->getStopName() << " "<< student->getStopName() << " (Route "<< student->getRouteID() <<") is Present " << endl;
            }
            else
            {
                cout <<  student->getStudentID() << " "<< student->getStopName() << " "<< student->getStopName() << " (Route "<< student->getRouteID() <<") cannot board the bus because of insufficient balance in the card " << endl;
            }
        }

        void displayBusInfo()
        {
            cout << "Bus ID : " << busID << endl;
            routes->displayStops();
        }
};

class TransportSystem
{
    private:
        Student **students;
        Bus **buses;
        int studentCount;
        int maxStudents;
        int busCount;
        int maxBuses;

    public:
        TransportSystem() : studentCount(0), maxStudents(0), busCount(0), maxBuses(0)
        {
            students = new Student*[maxStudents];
            buses = new Bus*[maxBuses];
        }

        TransportSystem(int maxStudents, int maxBuses) : studentCount(0), maxStudents(maxStudents), busCount(0), maxBuses(maxBuses)
        {
            students = new Student*[maxStudents];
            buses = new Bus*[maxBuses];
        }

        void addStudent(string id, string name, float balance, int routeID, string stop)
        {
            if(studentCount < maxStudents)
            {
                students[studentCount++] = new Student(id, name, balance, routeID, stop);
            }
            else
            {
                cout << "Can't Add more students" << endl;
            }
        }

        void addBus(int busID, Route *route)
        {
            if(busCount < maxBuses)
            {
                buses[busCount++] = new Bus(busID, route);
            }
            else
            {
                cout << "Can't Add more buses" << endl;
            }
        }

        void displayAllBuses()
        {
            for(int i = 0; i < busCount; i++)
            {
                cout << "Bus " << i+1 << endl;
                buses[i]->displayBusInfo();
            }
        }
        void displayAllStudents()
        {
            for(int i = 0; i < studentCount; i++ )
            {
                cout << "Student " << i+1 << endl;
                students[i]->displayStudent();
            }
        }

        ~TransportSystem()
        {
            for(int i = 0; i < studentCount; i++)
            {
                delete students[i];
            }
            delete[] students;

            for(int i = 0; i < busCount; i++)
            {
                delete buses[i];
            }
            delete[] buses;
        }
};

int main()
{
    TransportSystem ts(5, 2);

    ts.addStudent("24K-0001", "Ali", 45000, 5, "P.E.C.H.S");
    ts.addStudent("24K-0002", "Saad", 35000, 4, "North Nazimabad");

    Route r1("Route 1", 2);
    r1.addStop("P.E.C.H.S");
    r1.addStop("North Nazimabad");

    ts.addBus(101,&r1);

    cout << "\nStudents Info " << endl;
    ts.displayAllStudents();

    cout << "\nBuses Info " << endl;
    ts.displayAllBuses();
    return 0;
}