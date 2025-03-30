#include<iostream>
using namespace std;

class Vehicle
{
    protected:
        string vehicleID;
        static int activeDeliveries;

    public:
        Vehicle(string vehicleID) : vehicleID(vehicleID) { activeDeliveries++; }

        virtual void calculateRoute()
        {
            cout << "Calculating optimal route for vehicle " << vehicleID << endl;
        }

        virtual double estDeliveryTime(double distance) const
        {
            return distance / 50.0; 
        }
        
        static int getActiveDeliveries()
        {
            return activeDeliveries;
        }

        virtual void move()
        {
            cout << "Vehicle " << vehicleID << " is moving..." << endl;
        }

        friend bool compareEfficiency(const Vehicle& v1, const Vehicle& v2);
        friend bool operator==(const Vehicle& v1, const Vehicle& v2);
};
int Vehicle::activeDeliveries = 0;

class RamzanDrone : public Vehicle 
{
    public:
        RamzanDrone(string id) : Vehicle(id) {}
    
        void calculateRoute()
        {
            cout << "Drone " << vehicleID << " is calculating an aerial delivery route..." << endl;
        }
    
        double estDeliveryTime(double distance) const
        {
            return distance / 100.0;
        }
    
        void move() override
        {
            cout << "Drone " << vehicleID << " is flying to deliver the package..." << endl;
        }
};
    
class RamzanTimeShip : public Vehicle 
{
    public:
        RamzanTimeShip(string id) : Vehicle(id) {}
    
        void calculateRoute()
        {
            cout << "TimeShip " << vehicleID << " is verifying historical accuracy before traveling..." << endl;
        }
    
        double estDeliveryTime(double distance) const
        {
            return distance / 200.0;  
        }
    
        void move() override 
        {
            cout << "TimeShip " << vehicleID << " is warping through time..." << endl;
        }
};
    
class RamzanHyperPod : public Vehicle 
{
    public:
        RamzanHyperPod(string id) : Vehicle(id) {}
    
        void calculateRoute()
        {
            cout << "HyperPod " << vehicleID << " is navigating underground tunnels..." << endl;
        }
    
        double estDeliveryTime(double distance) const
        {
            return distance / 300.0;  
        }
    
        void move() override
        {
            cout << "HyperPod " << vehicleID << " is speeding through underground tunnels..." << endl;
        }
};

void command(Vehicle& v, string action, string packageID)
{
    cout << "Issuing command: " << action << " for package " << packageID << endl;
    v.move();
}

void command(Vehicle &v, string action, string packageID, string urgencyLevel) 
{
    cout << "Issuing command: " << action << " for package " << packageID << " with urgency level: " << urgencyLevel << endl;
    
    if (urgencyLevel == "urgent") 
    {
        cout << "Prioritizing urgent delivery..." << endl;
    }
    
    v.move();
}

bool compareEfficiency(const Vehicle& v1, const Vehicle& v2)
{
    return v1.estDeliveryTime(100.0) < v2.estDeliveryTime(100.0);
}

bool operator==(const Vehicle& v1, const Vehicle& v2)
{
    return v1.estDeliveryTime(100.0) == v2.estDeliveryTime(100.0);
}

int main()
{
    RamzanDrone drone("D1");
    RamzanTimeShip timeship("T1");
    RamzanHyperPod hyperpod("H1");

    command(drone, "Deliver", "PKG-001");
    command(timeship, "Deliver", "PKG-002", "urgent");
    command(hyperpod, "Deliver", "PKG-003");

    cout << endl;
    if(compareEfficiency(drone, timeship))
        cout << "Drone is more efficient than TimeShip for this delivery" << endl;
    else
        cout << "TimeShip is more efficient than Drone for this delivery" << endl;

    cout << endl;
    if(timeship == hyperpod)
        cout << "TimeShip and Hyperpod have the same efficiency" << endl;
    else
        cout << "TimeShip and Hyperpod differ in efficiency" << endl;
}