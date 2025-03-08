#include<iostream>
using namespace std;

class MarkerPen
{
    private:
        string brand;
        string color;
        int inkLevel;
        bool refillablity;

    public:
        void setValues(string brand, string color, int inkLevel, bool refillablity)
        {
            this->brand = brand;
            this->color = color;
            this->inkLevel = inkLevel;
            this->refillablity = refillablity;
        }

        string getBrand()
        {
            return brand;
        }

        string getColor()
        {
            return color;
        }

        int getInkLevel()
        {
            return inkLevel;
        } 

        bool getRefillablity()
        {
            return refillablity;
        }

        void write()
        {
            inkLevel -= 5;
        }

        void refill()
        {
            if(refillablity == true)
            {
                cout << "Refilling.... " << endl;
                inkLevel += 5;
            }
            else
            {
                cout << "Not Refillable"<<endl;
            }
        }
};

int main()
{
    MarkerPen markerPen1;
    markerPen1.setValues("Dollar","Black",100,true);
    cout << "Brand :  " << markerPen1.getBrand() <<endl;
    cout << "Color :  " << markerPen1.getColor() <<endl;
    cout << "Ink Level :  " << markerPen1.getInkLevel() <<endl;
    cout << "Refillablity Status :  " << ((markerPen1.getRefillablity()) ? "Yes" : "No") << endl;
    markerPen1.write();
    cout << "Ink Level After Writing : " << markerPen1.getInkLevel() << endl;
    markerPen1.refill();
    cout << "Ink Level After Refilling : " << markerPen1.getInkLevel() << endl;
}