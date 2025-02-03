#include<iostream>
using namespace std;

class TeaMug
{
    private:
        string brand;
        string color;
        int capacity;
        int currentFillLevel;

    public:
    void setValues(string brand, string color, int capacity, int currentFillLevel)
    {
        this->brand = brand;
        this->color = color;
        this->capacity = capacity;
        this->currentFillLevel = currentFillLevel;
    }

    string getBrand()
    {
        return brand;
    }

    string getColor()
    {
        return color;
    }

    int getCapacity()
    {
        return capacity;
    }

    int getCurrentFillLevel()
    {
        return currentFillLevel;
    }
    
    void sipTea()
    {
        if(currentFillLevel > 10 || capacity != 0)
        {
            cout << "Sipping Tea...." << endl;
            currentFillLevel -= 10;
        }
        else
        {
            cout << "Barely any tea left" << endl;
        }
    }

    void refill()
    {
        if((currentFillLevel + 10) > capacity)
        {
            cout << "The Tea Mug is Almost Full" << endl;
        }
        else
        {
            cout << "Refilling Tea..."<< endl;
            currentFillLevel += 10;
        }
    }

    bool checkForEmptyMug()
    {
        if(currentFillLevel == 0)
            return true;
        else
            return false;
    }
};

int main()
{

}