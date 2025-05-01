#include<iostream>
#include<fstream>
#include<exception>
using namespace std;

class TransportManagementSystem;

class User
{
    protected:
        string name;
        string role;
        string userID;
        bool paymentStatus;

    public:
        User(string name, string role, string userID, bool paymentStatus) : name(name), role(role), userID(userID), paymentStatus(paymentStatus) {}

        virtual float calculateFare(bool hasAc) = 0;

        string getName() const {return name;}
        string getID() const {return userID;}
        string getRole() const { return role;}
        bool hasPaid() const { return paymentStatus; }

        void printInfo()
        {
            cout << "Name : " << name << endl;
            cout << "ID : " << userID << endl;
            cout << "Role : " << role << endl;
            cout << "Payment Status : " << (paymentStatus ? "Paid" : "Not Paid") << endl;
        }

        friend class TransportManagementSystem;

        virtual ~User() {}
};

class Student : public User
{
    string rollNumber;
    string department;

    public:
        Student(string name, string role, string userID, bool paymentStatus, string rollNumber, string department)
            :User(name, role, userID, paymentStatus) , rollNumber(rollNumber) , department(department) {}

        float calculateFare(bool hasAC)
        {
            float baseFare = 5000.0;
            if(hasAC) 
                baseFare+= 2000.0;
            return baseFare; 
        }

        string getRollNumber() const { return rollNumber;}
        string getDepartment() const { return department;}

        void printStudentDetails()
        {
            User::printInfo();
            cout << "Roll Number : " << rollNumber << endl;
            cout << "Department : " << department << endl;
        }

};

class Faculty : public User
{
    string empID;
    string department;

    public:
        Faculty(string name, string role, string userID, bool paymentStatus, string empID, string department)
            :User(name, role, userID, paymentStatus) , empID(empID) , department(department) {}

        float calculateFare(bool hasAC)
        {
            float baseFare = 7000.0;
            if(hasAC) 
                baseFare+= 2000.0;
            return baseFare; 
        }

        string getEmployeeID() const { return empID;}
        string getDepartment() const { return department;}

        void printStudentDetails()
        {
            User::printInfo();
            cout << "Employee ID : " << empID << endl;
            cout << "Department : " << department << endl;
        }


};


class Seat 
{
    int seatNumber;
    string seatType; 
    bool isBooked;
    User* assignedUser;

    public:
        Seat(int sN, string type) : seatNumber(sN), seatType(type), isBooked(false) {}
    
        bool book() 
        {
            if (!isBooked) 
            {
                isBooked = true;
                return true;
            }
            return false;
        }
    
        string getType() const { return seatType; }
        bool getStatus() const { return isBooked; }
        int getNumber() const { return seatNumber; }

        void assign(User* u, int seatIndex)
        {
            assignedUser = u;
            seatNumber = seatIndex;
            isBooked = (u != nullptr);
        }
};
     

class Driver
{
    string driverID;
    string name;
    string licenseNumber;
    string contactInfo;
    bool isAssigned;

    public:
        Driver(string ID, string name, string lN, string conInfo) : driverID(ID), name(name), licenseNumber(lN), contactInfo(conInfo){}

        void assignDriver() { isAssigned = 1; }
        void unassignDriver() { isAssigned = 0;}

        void printDriverDetails() 
        {
            cout << "Driver ID : " << driverID << endl;
            cout << "Name : " << name << endl;
            cout << "License Number : " << licenseNumber << endl;
            cout << "Contact : " << contactInfo << endl;
            cout << "Assignment Status : " << (isAssigned ? "Assigned" : "Not Assigned") << endl;
        }

        friend class TransportManagementSystem;
};

class Route
{
    int routeID;
    string startLocation;
    string endLocation;
    float distance;
    bool isLongDistance;

    public:
        Route(int rID,string sL, string eL, float d) : routeID(rID), startLocation(sL), endLocation(eL), distance(d)
        {
            isLongDistance = checkForLongDistances();
        }


        bool checkForLongDistances()
        {
            if(distance >= 30.0)
                return true;
            return false;
        }

        void printRouteDetails() 
        {
            cout << "Route ID: " << routeID << endl;
            cout << "From: " << startLocation << " To: " << endLocation << endl;
            cout << "Distance: " << distance << " km" << endl;
            cout << "Long Distance: " << (isLongDistance ? "Yes" : "No") << endl;
        }

        friend class TransportManagementSystem;
};

class IndexOutOfRangeException : public std::exception 
{
    public:
    
        const char* what() const noexcept override 
        {
            return "IndexOutOfRangeError - Index is out of range";
        }
};


class Vehicle
{
    protected:
        string vehicleID;
        bool isAC;
        Driver* driver;
        Route* route;
        Seat** seats;
        int totalSeats;
        string type;

    public:
        Vehicle(string id, bool ac, int capacity, string t) : vehicleID(id), isAC(ac), totalSeats(capacity), type(t)
        {
            seats = new Seat*[totalSeats];
            for(int i = 0; i < totalSeats; i++)
            {
                string seatRole = (i < totalSeats / 2) ? "Student" : "Faculty";
                seats[i] = new Seat(i+1,seatRole);
                seats[i]->assign(nullptr, i);
            }
        }

        int getTotalSeats() const { return totalSeats; }
        Seat* getSeat(int index)
        {
            if (index < 0 || index >= totalSeats) throw IndexOutOfRangeException();

            return seats[index];
        }

        virtual void display() = 0;

        void assignDriver(Driver *d) { driver = d; }
        void assignRoute(Route *r) { route = r;}

        friend class TransportManagementSystem;
};

class Bus : public Vehicle
{
    public:
        Bus(string id, bool ac) : Vehicle(id, ac, 52, "Bus") {}

        void display()
        {
            cout << "Bus ID :" << vehicleID << endl;
            cout << "AC : " << (isAC ? "Yes" : "No") << endl;
            for(int i = 0; i < totalSeats; i++)
            {
                cout << "Seat" << seats[i]->getNumber() << "(" << seats[i]->getType() << ") - " << (seats[i]->getStatus() ? "Booked" : "Available") << endl; 
            }
        }
};

class Coaster : public Vehicle
{
    public:
        Coaster(string id, bool ac) : Vehicle(id, ac, 32, "Coaster") {}

        void display()
        {
            cout << "Coaster ID :" << vehicleID << endl;
            cout << "AC : " << (isAC ? "Yes" : "No") << endl;
            for(int i = 0; i < totalSeats; i++)
            {
                cout << "Seat" << seats[i]->getNumber() << "(" << seats[i]->getType() << ") - " << (seats[i]->getStatus() ? "Booked" : "Available") << endl; 
            }
        }
};

class PaymentException : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "Payment not completed. Booking cannot be processed";
        }
};

class SeatUnavailableException  : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "The requested seat is not available.";
        }
};

class RoleViolationException  : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "This seat is not available for your role.";
        }
};

class EntityNotFoundException  : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "The requested entity was not found.";
        }
};

class MonthlyBookingLimitException  : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "Monthly booking limit reached. You can only book one seat per month.";
        }
};

class Booking
{
    int bookingID;
    User* user;
    Vehicle* vehicle;
    Seat* seat;
    string bookingDate;
    bool isActive;
    static int nextBookingId;

    public:
        Booking(User* u, Vehicle* v, Seat* s, string date) : user(u), vehicle(v), seat(s), bookingDate(date)
        {
            bookingID = nextBookingId++;

            if(!user->hasPaid()) throw PaymentException();

            if(seat->getStatus()) throw SeatUnavailableException();

            if((user->getRole() == "Student" && seat->getType() != "Student") || (user->getRole() == "Faculty" && seat->getType() != "Faculty")) throw RoleViolationException();

            seat->book();
            seat->assign(user, seat->getNumber() - 1 );
        }

        void cancelBooking() {isActive = false;}

        void printBookingDetails()
        {
            cout << "Booking ID: " << bookingID << endl;
            cout << "User Name: " << user->getName() << endl;
            cout << "User ID : " << user->getID() << endl;
            cout << "Seat Number: " << seat->getNumber() << endl;
            cout << "Booking Date: " << bookingDate << endl;
            cout << "Status: " << (isActive ? "Active" : "Cancelled") << endl;
        }

        friend class TransportManagementSystem;
};

int Booking::nextBookingId = 1000;

class Transporter
{
    string transporterID;
    string name;
    string contactNumber;

    public:
        Transporter(string id, string name, string contact) : transporterID(id), name(name), contactNumber(contact) {}

        void printDetails()
        {
            cout << "Transporter ID : " << transporterID << endl;
            cout << "Name : " << name << endl;
            cout << "Contact Number : " << contactNumber << endl;
        }

        friend class TransportManagementSystem;
};

template <class T>
class TemplateClass
{
    T* data[100];
    int count;

    public:
        TemplateClass() { count = 0;}

        void add(T* obj)
        {
            if(count < 100)
            {
                data[count++] = obj;
            }
            else
            {
                throw IndexOutOfRangeException();
            }
        }

        T* get(int index)
        {
            if(index < 0 || index >= count)
                throw IndexOutOfRangeException();
            
                return data[index];
        }

        int getCount() const { return count;}

};

class TransportManagementSystem
{
    TemplateClass<User> users;
    TemplateClass<Driver> drivers;
    TemplateClass<Route> routes;
    TemplateClass<Vehicle> vehicles;
    TemplateClass<Booking> bookings;
    TemplateClass<Transporter> transporters;

    public:
        void addUser(User* u) 
        { 
            try 
            {
                users.add(u);
                cout << "User added successfully!" << endl;
            }
            catch (const IndexOutOfRangeException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        void addDriver(Driver* d)
        { 
            try 
            {
                drivers.add(d); 
                cout << "User added successfully!" << endl;
            }
            catch (const IndexOutOfRangeException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        void addRoute(Route* r) 
        { 
            try 
            {
                routes.add(r);
                cout << "User added successfully!" << endl;
            }
            catch (const IndexOutOfRangeException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        void addVehicle(Vehicle* v) 
        { 
            try 
            {
                vehicles.add(v); 
                cout << "User added successfully!" << endl;
            }
            catch (const IndexOutOfRangeException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        void addTransporter(Transporter* t) 
        {
            try 
            {
                transporters.add(t); 
                cout << "User added successfully!" << endl;
            }
            catch (const IndexOutOfRangeException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }

        void bookSeat(User* u, Vehicle* v, int seatIndex, string date)
        {
            try 
            {
                if(seatIndex < 0 || seatIndex >= v->getTotalSeats())
                {
                    throw IndexOutOfRangeException();
                }

                Seat* seat = v->getSeat(seatIndex);
                Booking* b = new Booking(u, v, seat, date);
                bookings.add(b);
                cout << "Booking successful!" << endl;
            }
            catch (const IndexOutOfRangeException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            catch (const PaymentException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            catch (const SeatUnavailableException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            catch (const RoleViolationException& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }

        void viewAllUsers()
        {
            for(int i = 0; i < users.getCount(); i++)
            {
                users.get(i)->printInfo(); 
            }
        }

        void viewAllBookings()
        {
            for(int i = 0; i < bookings.getCount(); i++)
            {
                bookings.get(i)->printBookingDetails();
            }
        }

        void viewAllRoutes()
        {
            for(int i = 0; i < routes.getCount(); i++)
            {
                routes.get(i)->printRouteDetails();
            }
        }

        void viewAllDrivers()
        {
            for(int i = 0; i < drivers.getCount(); i++)
            {
                drivers.get(i)->printDriverDetails();
            }
        }

        void viewAllTransporters()
        {
            for(int i = 0; i < transporters.getCount(); i++)
            {
                transporters.get(i)->printDetails();
            }
        }

        
        void saveToFile()
        {
            ofstream userFile("users.txt");
            userFile << "Name, ID, Role, Payment Status" << endl;
            for (int i = 0; i < users.getCount(); i++) 
            {
                User* u = users.get(i);
                userFile << u->getName() << ", "<< u->getID() << ", "<< u->getRole() << ", " << (u->hasPaid() ? "Paid" : "Not Paid") << endl;
            }
            userFile.close();

            ofstream driverFile("drivers.txt");
            driverFile << "Driver ID, Name, License Number, Contact Info" << endl;
            for (int i = 0; i < drivers.getCount(); i++) 
            {
                Driver* d = drivers.get(i);
                driverFile << d->driverID << ", "<< d->name << ", " << d->licenseNumber << ", " << d->contactInfo << endl;
            }
            driverFile.close();

            ofstream routeFile("routes.txt");
            routeFile << "Route ID, Start Location, End Location, Distance, Type" << endl;
            for (int i = 0; i < routes.getCount(); i++) 
            {
                Route* r = routes.get(i);
                routeFile << r->routeID << ", "<< r->startLocation << ", "<< r->endLocation << ", "<< r->distance << ", "<< (r->checkForLongDistances() ? "Long Distance" : "Short Distance") << endl;
            }
            routeFile.close();
            
            ofstream transporterFile("transporters.txt");
            transporterFile << "Transporter ID, Name, Contact Number" << endl;
            for (int i = 0; i < transporters.getCount(); i++) 
            {
                Transporter* t = transporters.get(i);
                transporterFile << t->transporterID << ", " << t->name << ", " << t->contactNumber << endl;
            }
            transporterFile.close();
            
            cout << "All records have been saved to files with headings." << endl;
        }
};

Student* createStudent() 
{
    string name, id, studentId, department;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter user ID (CNIC): ";
    cin >> id;
    cout << "Enter department: ";
    cin >> department;
    cout << "Enter student ID (specific): ";
    cin >> studentId;

    return new Student(name, "Student", id, true, studentId, department);
}

Faculty* createFaculty() 
{
    string name, id, facultyId, department;
    cout << "Enter faculty name: ";
    cin >> name;
    cout << "Enter user ID (CNIC): ";
    cin >> id;
    cout << "Enter department: ";
    cin >> department;
    cout << "Enter faculty ID (specific): ";
    cin >> facultyId;

    return new Faculty(name, "Faculty", id, true, facultyId, department);
}

Driver* createDriver() 
{
    string driverId, name, license, contact;
    cout << "Enter driver ID: ";
    cin >> driverId;
    cout << "Enter driver name: ";
    cin >> name;
    cout << "Enter license number: ";
    cin >> license;
    cout << "Enter contact number: ";
    cin >> contact;

    return new Driver(driverId, name, license, contact);
}

Route* createRoute() 
{
    int routeId;
    string start, end;
    float distance;
    cout << "Enter route ID: ";
    cin >> routeId;
    cout << "Enter start location: ";
    cin >> start;
    cout << "Enter end location: ";
    cin >> end;
    cout << "Enter distance (in km): ";
    cin >> distance;

    return new Route(routeId, start, end, distance);
}


Transporter* createTransporter() 
{
    string transporterId, name, contact;
    cout << "Enter transporter ID: ";
    cin >> transporterId;
    cout << "Enter transporter name: ";
    cin >> name;
    cout << "Enter transporter contact: ";
    cin >> contact;

    return new Transporter(transporterId, name, contact);
}

int main() 
{
    TransportManagementSystem tms;
    int choice;

    do 
    {
        cout << "\n--- Transport Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Faculty" << endl;
        cout << "3. Add Driver" << endl;
        cout << "4. Add Route" << endl;
        cout << "5. Add Transporter" << endl;
        cout << "6. View All Users" << endl;
        cout << "7. View All Drivers" << endl;
        cout << "8. View All Routes" << endl;
        cout << "9. View All Transporters" << endl;
        cout << "10. Save all the records to the file" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                {
                    Student* newStudent = createStudent();
                    tms.addUser(newStudent);
                    cout << "Student added successfully!" << endl;
                }
                break;

            case 2:
                {
                    Faculty* newFaculty = createFaculty();
                    tms.addUser(newFaculty);
                    cout << "Faculty added successfully!" << endl;
                }
                break;

            case 3:
                {
                    Driver* newDriver = createDriver();
                    tms.addDriver(newDriver);
                    cout << "Driver added successfully!" << endl;
                }
                break;

            case 4:
                {
                    Route* newRoute = createRoute();
                    tms.addRoute(newRoute);
                    cout << "Route added successfully!" << endl;
                }
                break;

            case 5:
                {
                    Transporter* newTransporter = createTransporter();
                    tms.addTransporter(newTransporter);
                    cout << "Transporter added successfully!" << endl;
                }
                break;

            case 6:
                cout << "\nAll Users: " << endl;
                tms.viewAllUsers();
                break;

            case 7:
                cout << "\nAll Drivers: " << endl;
                tms.viewAllDrivers();
                break;

            case 8:
                cout << "\nAll Routes: " << endl;
                tms.viewAllRoutes();
                break;

            case 9:
                cout << "\nAll Transporters: " << endl;
                tms.viewAllTransporters();
                break;

            case 10:
                cout << "Saving all records to file..." << endl;
                tms.saveToFile();
                cout << "Records saved successfully!" << endl;
                break;
            
            case 11:
                cout << "Exiting the system." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 11);

    return 0;
}