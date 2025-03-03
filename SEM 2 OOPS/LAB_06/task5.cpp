#include<iostream>
using namespace std;

class Device
{
    int deviceID;
    bool status;

    public:
        Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

        void displayDetails()
        {
            cout << "Device ID: " << deviceID << endl;
            cout << "Status: " << (status ? "ON" : "OFF") << endl;
        }
};

class SmartPhone : virtual public Device
{   
    protected:
        float screenSize;
    
    public:
        SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

        void displayDetails()
        {
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << " inches" << endl;
        }
};

class SmartWatch : virtual public Device
{
    protected:
    bool heartRateMonitor;

    public:
        SmartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

        void displayDetails()
        {
            Device::displayDetails();
            cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
    int stepCounter;

    public:
        SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
            : Device(deviceID, status), SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

        void displayDetails()
        {
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << " inches" << endl;
            cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
            cout << "Step Counter: " << stepCounter << endl;
        }
};

int main()
{
    SmartWearable smartWearableDevice(1, true, 6.5, true, 10000);
    smartWearableDevice.displayDetails();
}