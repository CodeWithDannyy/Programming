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
            currentFillLevel += 15;
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
    TeaMug cupOfTea;
    cupOfTea.setValues("Lipton","White",100,50);
    cout << "Brand : " << cupOfTea.getBrand() << endl;
    cout << "Color : " << cupOfTea.getColor() << endl;
    cout << "Capcity : " << cupOfTea.getCapacity() << endl;
    cout << "Current Fill Level : " << cupOfTea.getCurrentFillLevel() << endl;
    cout << "Time to sip...." << endl;
    cout << "Checking if the mug is empty or not : " << ((cupOfTea.checkForEmptyMug()) ? "Mug is Empty" : "Mug is not Empty") << endl;
    cupOfTea.sipTea();
    cout << "Current Fill Level After sipping tea : " << cupOfTea.getCurrentFillLevel() << endl;
    cupOfTea.refill();
    cout << "Current Fill Level After refilling tea mug : " << cupOfTea.getCurrentFillLevel() << endl;
}