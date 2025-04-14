#include<iostream>
using namespace std;

class Vehicle
{
    protected:
        string model;
        double rate;

    public:
        Vehicle(string model, double rate) : model(model), rate(rate) {} 
        virtual double getDailyRate() const = 0;
        virtual void displayDetails() = 0;
};

class Car : public Vehicle
{
    public:
    Car() : Vehicle("Toyota",900000.0) {}

    double getDailyRate() const
    {
        return rate;
    }

    void displayDetails()
    {
        cout << "--- Car Details ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }
};

class Bike : public Vehicle
{
    public:
        Bike() : Vehicle("Honda 125",100000.0) {}

        double getDailyRate() const
        {
            return rate;
        }

        void displayDetails()
        {
            cout << "--- Bike Details ---" << endl;
            cout << "Model: " << model << endl;
            cout << "Rate: " << rate << endl;
        }
};

int main()
{
    Car c1;
    Bike b1;
    
    c1.getDailyRate();
    c1.displayDetails();
    cout << endl;
    b1.getDailyRate();
    b1.displayDetails();
    return 0;
}