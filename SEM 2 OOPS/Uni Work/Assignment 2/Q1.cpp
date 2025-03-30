#include<iostream>
using namespace std;

class User
{
    protected:
        string ID;
        string name;
        float cardBalance;
        int routeID;
        string stopName;

    public:
        User(string ID, string name, float cardBalance, int routeID, string stopName) 
            : ID(ID), name(name), cardBalance(cardBalance), routeID(routeID), stopName(stopName) {}


        virtual void payFee(float amount)
        {
            cout << "Paying fees..." << endl;
        }

        virtual void displayUser()
        {
            cout << "ID : " << ID << endl;
            cout << "Name : " << name << endl;
            cout << "Card Balance : " << cardBalance << endl;
            cout << "Route ID : " << routeID << endl;
            cout << "Stop Name : " << stopName << endl;
        }
    
        bool canBoard() { return cardBalance > 0.0; }
        string getID() const { return ID; }
        int getRouteID() const { return routeID; }
        string getStopName() const { return stopName; }
    
        virtual ~User() {}
};

class Student : public User
{
    public:
        Student(string ID, string name, float cardBalance, int routeID, string stopName) 
            : User(ID, name, cardBalance, routeID, stopName) {}

        void payFee(float amount)
        {
            if(cardBalance >= amount) 
            {
                cardBalance -= amount;
                cout << "Student's Semester Fee Paid. Remaining Balance: " << cardBalance << endl;
            } 
            else 
            {
                cout << "Insufficient Balance! Please recharge your card." << endl;
            }
        }
};

class Teacher : public User 
{
    public:
        Teacher(string ID, string name, float cardBalance, int routeID, string stopName) 
            : User(ID, name, cardBalance, routeID, stopName) {}

        void payFee(float amount)
        {
            if(cardBalance >= amount) 
            {
                cardBalance -= amount;
                cout << "Teacher's Monthly Fee Paid. Remaining Balance: " << cardBalance << endl;
            } 
            else 
            {
                cout << "Insufficient Balance! Please recharge your card." << endl;
            }
        }
};

class Staff : public User 
{
    public:
        Staff(string ID, string name, float cardBalance, int routeID, string stopName) 
            : User(ID, name, cardBalance, routeID, stopName) {}

        void payFee(float amount)
        {
            if(cardBalance >= amount) 
            {
                cardBalance -= amount;
                cout << "Staff's Monthly Fee Paid. Remaining Balance: " << cardBalance << endl;
            } 
            else 
            {
                cout << "Insufficient Balance! Please recharge your card." << endl;
            }
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

        bool operator==(const Route& object) 
        {
            if(stopCount != object.stopCount) return false;
            for(int i = 0; i < stopCount; i++)
            {
                if(stops[i] != object.stops[i])
                {
                    return false;
                }
            }
            return true;
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
        
        void recordAttendance(User *user) 
        {
            if(user->canBoard()) 
            {
                cout <<  user->getID() << " (" << user->getStopName() << ") Route " << user->getRouteID() << " is Present." << endl;
            } 
            else 
            {
                cout <<  user->getID() << " (" << user->getStopName()  << ") Route " << user->getRouteID() << " cannot board due to insufficient balance." << endl;
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
    User **users;
    int userCount;
    int maxUsers;
    Bus **buses;
    int busCount;
    int maxBuses;

    public:
        TransportSystem(int maxUsers, int maxBuses) : userCount(0), maxUsers(maxUsers), busCount(0), maxBuses(maxBuses)
        {
            users = new User*[maxUsers];
            buses = new Bus*[maxBuses];
        }

        void addUser(User *user) 
        {
            if(userCount < maxUsers) 
            {
                users[userCount++] = user;
            } 
            else 
            {
                cout << "Can't Add More Users" << endl;
            }
        }

        void addBus(Bus *bus) 
        {
            if(busCount < maxBuses) 
            {
                buses[busCount++] = bus;
            } 
            else 
            {
                cout << "Can't add more buses" << endl;
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

        void displayAllUsers()
        {
            for(int i = 0; i < userCount; i++ )
            {
                cout << "Student " << i+1 << endl;
                users[i]->displayUser();
            }
        }

        ~TransportSystem()
        {
            for(int i = 0; i < userCount; i++)
            {
                delete users[i];
            }
            delete[] users;

            for(int i = 0; i < busCount; i++)
            {
                delete buses[i];
            }
            delete[] buses;
        }
};

int main()
{
    TransportSystem ts(6,3);

    Student s1("24K-0001", "Danny", 45000, 5, "P.E.C.H.S");
    Student s2("24K-0002", "Altaf", 35000, 4, "North Nazimabad");

    Teacher t1("TCH-1001", "Dr. Ahmed", 100000, 3, "Gulshan");
    Teacher t2("TCH-1002", "Prof. Ayesha", 90000, 2, "DHA");

    Staff staff1("STF-2001", "Mr. Kamal", 50000, 1, "Malir");
    Staff staff2("STF-2002", "Ms. Sara", 45000, 2, "Saddar");

    ts.addUser(&s1);
    ts.addUser(&s2);
    ts.addUser(&t1);
    ts.addUser(&t2);
    ts.addUser(&staff1);
    ts.addUser(&staff2);

    Route r1("Route 1", 3);
    r1.addStop("P.E.C.H.S");
    r1.addStop("North Nazimabad");
    r1.addStop("Saddar");

    Route r2("Route 2", 3);
    r2.addStop("Gulshan");
    r2.addStop("DHA");
    r2.addStop("Malir");

    Bus bus1(101, &r1);
    Bus bus2(102, &r2);

    ts.addBus(&bus1);
    ts.addBus(&bus2);

    cout << "--- Displaying All Users ---" << endl;
    ts.displayAllUsers();

    cout << "--- Displaying All Buses ---" << endl;
    ts.displayAllBuses();

    cout << "\nFee Payments" << endl;
    s1.payFee(20000);
    t1.payFee(10000);
    staff1.payFee(5000);

    cout << "\nBus Attendance " << endl;
    bus1.recordAttendance(&s1);
    bus1.recordAttendance(&t1);
    bus2.recordAttendance(&staff1);

    cout << "\nComparing Routes using operator overloading" << endl;
    if(r1 == r2)
    {
        cout << "Routes are the same" << endl;
    }
    else
    {
        cout << "Routes are different" << endl;
    }
    return 0;
}