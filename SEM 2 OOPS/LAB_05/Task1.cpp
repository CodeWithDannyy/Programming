#include <iostream>
using namespace std;

class Car
{
private:
    int registrationNumber;
    string model;
    string ownerName;

public:
    Car() : registrationNumber(0), model("Unknown"), ownerName("Unknown") {};
    Car(int registrationNumber, string model, string ownerName) : registrationNumber(registrationNumber), model(model), ownerName(ownerName) {}
    Car(const Car &obj, string newOwner)
    {
        registrationNumber = obj.registrationNumber;
        model = obj.model;
        ownerName = newOwner;
    }

    void display()
    {
        cout << "Car Deatils : " << endl;
        cout << "Registration Number : " << registrationNumber << endl;
        cout << "Model : " << model << endl;
        cout << "Owner Name : " << ownerName << endl;
    }
};

int main()
{
    Car car1(102345, "Toyota", "Ali");
    car1.display();
    Car car2(car1, "Faris");
    car2.display();

    return 0;
}