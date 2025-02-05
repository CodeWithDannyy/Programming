#include<iostream>
using namespace std;

class Laptop
{
    private:
        string brand;
        string model;
        string processor;
        int RAM;
        int storage;
    public:
        void setValues(string brand, string model, string processor, int RAM, int storage)
        {
            this->brand = brand;
            this->model = model;
            this->processor = processor;
            this->RAM = RAM;
            this->storage = storage;
        }
        
        void turnOnLaptop()
        {
            cout << "Laptop turned On" << endl;
        }

        void turnOffLaptop()
        {
            cout << "Laptop turned Off" << endl;
        }

        void runAProgram()
        {
            cout << "Running A Program...." << endl;
        }

        void checkSpecifications()
        {
            cout << "Specifications : " << endl;
            cout << "Brand : " << brand << endl;
            cout << "Model : " << model << endl;
            cout << "Processor : " << processor << endl;
            cout << "RAM : " << RAM << " GBs" << endl;
            cout << "Storage : " << storage << endl;
        }
};

int main()
{
    Laptop Bilal, Ayesha;

    Bilal.setValues("Dell", "XPS 17", "Intel Core i9", 32, 1024);
    Ayesha.setValues("Acer" , "Aspire 5" , "Intel Core i5", 8, 512);

    cout << "Bilal's Laptop: " << endl;
    Bilal.turnOnLaptop();
    Bilal.checkSpecifications();
    Bilal.runAProgram();
    Bilal.turnOffLaptop();

    cout << "\nAyesha's Laptop: " << endl;
    Ayesha.turnOnLaptop();
    Ayesha.checkSpecifications();
    Ayesha.runAProgram();
    Ayesha.turnOffLaptop();
    return 0;
}