#include <iostream>
using namespace std;

class Vehicle
{
private:
    string brand;
    int speed;

public:
    Vehicle(string brand, int speed)
        : brand(brand), speed(speed) {}

    void displayDetails()
    {
        cout << "Brand : " << brand << endl;
        cout << "Speed : " << speed << endl;
    }
};

class Car : public Vehicle
{
    int seats;

public:
    Car(string brand, int speed, int seats)
        : Vehicle(brand, speed), seats(seats) {}

    void displayDetails()
    {
        Vehicle::displayDetails();
        cout << "Seats : " << seats << endl;
    }
};

class ElectricCar : public Car
{
    int batteryLife;

public:
    ElectricCar(string brand, int speed, int seats, int batteryLife)
        : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails()
    {
        Car::displayDetails();
        cout << "Battery Life : " << batteryLife << " hours " << endl;
    }
};

int main()
{
    ElectricCar ev1("Nissan", 200, 5, 50);
    ev1.displayDetails();
}