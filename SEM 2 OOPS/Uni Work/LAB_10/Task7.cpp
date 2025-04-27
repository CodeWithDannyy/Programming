#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outFile("sensor_log.txt");
    if(!outFile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    outFile << "Sensor 1: 25.5 C" << endl;
    cout << "Now the put pointer is at " << outFile.tellp() << endl;
    
    outFile << "Sensor 2: 98.1 %RH" << endl;
    cout << "Now the put pointer is at " << outFile.tellp() << endl;

    outFile.close();
    return 0;
}