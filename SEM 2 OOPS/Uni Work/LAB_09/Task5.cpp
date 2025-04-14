#include <iostream>
using namespace std;

class Activity 
{
    public:
        virtual double calculateCaloriesBurned() const = 0;
        virtual ~Activity() {}
};

class Running : public Activity 
{
    double distance; 
    double time;    

    public:
        Running(double distance, double time) : distance(distance), time(time) {}

        double calculateCaloriesBurned() const 
        {
            double weight = 70.0;
            return 1.036 * weight * distance;
        }
};

class Cycling : public Activity 
{
    double speed; 
    double time;  

    public:
        Cycling(double speed, double time) : speed(speed), time(time) {}

        double calculateCaloriesBurned() const
        {
            double weight = 70.0;
            double MET;
            if (speed < 16) MET = 4;
            else if (speed <= 20) MET = 8;
            else MET = 10;

            return MET * weight * time;
        }
};


int main() 
{
    Running run(5.0, 30);   
    Cycling bike(18.0, 1.0);   

    Activity* activity;

    activity = &run;
    cout << "Calories burned during running: " << activity->calculateCaloriesBurned() << " kcal\n";

    activity = &bike;
    cout << "Calories burned during cycling: " << activity->calculateCaloriesBurned() << " kcal\n";

    return 0;
}
