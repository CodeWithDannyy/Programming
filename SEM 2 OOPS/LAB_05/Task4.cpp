#include<iostream>
using namespace std;

class Battery
{
    private:
        int capacity;

    public:
        Battery(int capacity) : capacity(capacity) {}

        void displayBatteryDetails() const
        {
            cout << "Battery Capacity: " << capacity << " mAh" << endl;
        }
};

class SmartPhone
{
    private:
        Battery battery;
        string model;
        int memorySize;
    
    public:
        SmartPhone(string model, int memorySize, int capacity) : model(model), memorySize(memorySize), battery(capacity) {}

        void displaySmartPhoneDetails()
        {
            cout << "Smart Phone Model: " << model << endl;
            cout << "Memory Size: " << memorySize << " GB" << endl;
            battery.displayBatteryDetails();
        }
};

int main()
{
    SmartPhone mySmartPhone("iPhone 14 Pro ", 12, 3200);

    mySmartPhone.displaySmartPhoneDetails();

    return 0;
}