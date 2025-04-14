#include<iostream>
using namespace std;

class SmartDevice
{
    public:
        virtual void turnOn() = 0 ;
        virtual void turnOff() = 0 ;
        virtual bool getStatus() = 0 ;      
};

class LightBulb : public SmartDevice
{
    bool isOn;
    int brightness;

    public:
        LightBulb() : isOn(false), brightness(0) {}
        void turnOn()
        {
            isOn = true;
        }
        void turnOff()
        {
            isOn = false;
        }
        bool getStatus()
        {
            return isOn;
        }
};

class Thermostat : public SmartDevice
{
    bool isOn;
    double temperature ;

    public:
        Thermostat() : isOn(false), temperature(32) {}
        void turnOn()
        {
            isOn = true;
        }
        void turnOff()
        {
            isOn = false;
        }
        bool getStatus()
        {
            return isOn;
        }
};

int main()
{
    LightBulb lb;
    Thermostat tmst;

    cout << "Light bulb Status : " << ((lb.getStatus())? "On" : "Off") << endl;
    lb.turnOn();
    cout << "Changed Light bulb Status : " << ((lb.getStatus())? "On" : "Off") << endl;

    cout << "Thermostat Status : " << ((tmst.getStatus())? "On" : "Off") << endl;
    tmst.turnOn();
    cout << "Changed Thermostat Status : " << ((tmst.getStatus())? "On" : "Off") << endl;
    return 0;
}