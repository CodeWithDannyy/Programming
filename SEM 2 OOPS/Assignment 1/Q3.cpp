#include<iostream>
#include<iomanip>
using namespace std;

class Vehicle
{
    private:
        string model;
        double rentalPrice;
        string requiredLicense;
    
    public:
        Vehicle(string model, double rentalPrice, string requiredLicense) : model(model), rentalPrice(rentalPrice), requiredLicense(requiredLicense) {}

        bool isEligible(string userLicense) { return userLicense == requiredLicense; }
        
        void display()
        {
            cout << "Model: " << model << endl;
            cout << "Rental Price: " << fixed << setprecision(2) << rentalPrice << endl;
            cout << "Required License: " << requiredLicense << endl;
        }
};


class User
{
    private:
        string name;
        int age;
        string licenseType;
        string contactInformation;
        int userID;
    
    public: 
        User() : name("Unknown"), age(0), licenseType("Unknown"), contactInformation("Unknown") , userID(0) {}

        User(string name, int age, string licenseType, string contactInformation, int userID) : name(name), age(age), licenseType(licenseType), contactInformation(contactInformation), userID(userID) {}

        void updateDetails(string name, int age, string licenseType, string contactInformation)
        {
            this->name = name;
            this->age = age;
            this->licenseType = licenseType;
            this->contactInformation = contactInformation;
        }

        string getLicenseType() const { return licenseType; }

        void displayUser()
        {
            cout << "User Details: " << endl;
            cout << "Name : " << name << endl;
            cout << "Age : " << age << endl;
            cout << "License Type : " << licenseType << endl;
            cout << "Contact Information : " << contactInformation << endl;
        }
};

class RentalSystem
{
    private:
        Vehicle **vehicles;
        int vehicleCount;
        int maxVehicles;
    public:
        RentalSystem(int maxVehicles) : vehicleCount(0), maxVehicles(maxVehicles) 
        {
            vehicles = new Vehicle*[maxVehicles];
        }

        void addVehicle(string model, double price, string requiredLicense)
        {
            if(vehicleCount < maxVehicles)
            {
                vehicles[vehicleCount++] = new Vehicle(model, price, requiredLicense);
            }
            else
                cout << "Vehicle list is full" << endl;
        }

        void displayAllVehicles()
        {
            for(int i = 0; i < vehicleCount; i++)
            {
                cout << "Vehcile " << i+1 << endl;
                vehicles[i]->display();
            }
        }

        void rentVehicle(User *user, int vehicleIndex)
        {
            if(vehicleIndex < 0 || vehicleIndex >= vehicleCount)
            {
                cout << "Invalid vehicle Index" << endl;
                return;
            }

            if(vehicles[vehicleIndex]->isEligible(user->getLicenseType()))
            {
                cout << "Vehicle rented successfully" << endl;
                vehicles[vehicleIndex]->display();
            }
            else    
                cout << "You are not elligible to rent this vehicle" << endl;
        }

        ~RentalSystem()
        {
            for(int i = 0; i < vehicleCount; i++)
            {
                delete vehicles[i];
            }
            delete[] vehicles;
        }

};

int main()
{
    RentalSystem system(5);
    system.addVehicle("Toyota", 3000000, "Full");
    system.addVehicle("Honda", 1500000, "Intermediate");
    system.addVehicle("Ford", 25000000, "Full");

    User user1("Albert Camus", 59, "Full", "albert.camus@gmail.com",101);
    user1.displayUser();
    cout << endl;

    system.displayAllVehicles();

    cout << "\nRenting Vehicle 1" << endl;
    system.rentVehicle(&user1, 0);
    cout << "\nRenting Vehicle 2" << endl;
    system.rentVehicle(&user1, 1);

    return 0;
}