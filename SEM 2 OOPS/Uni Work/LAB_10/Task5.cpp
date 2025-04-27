#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ifstream inpFile("vehicles.txt");

    if(!inpFile.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    string type,id,name,extraData,certification;
    string line;
    int year, battery;
    float softwareVersion;

    while(getline(inpFile, line))
    {
        istringstream iss(line);
        getline(iss,type,',');
        getline(iss,id,',');
        getline(iss,name,',');
        getline(iss,line,',');
        year = stoi(line);
        getline(iss,extraData,',');
        getline(iss,certification,',');
        
        if(type == "AutonomousCar")
        {
            size_t pos = extraData.find(':');
            if(pos == string::npos)
            {
                cout << "Colon (:) not found" << endl;
            }
            else
            {
                string afterColon = extraData.substr(pos + 1);
                softwareVersion = stof(afterColon);
                cout << "ID : " << id << ", Software Version : " << softwareVersion << endl;
            }
        }
        else if (type == "ElectricVehicle")
        {
            size_t pos = extraData.find(':');
            if(pos == string::npos)
            {
                cout << "Colon (:) not found" << endl;
            }
            else
            {
                string afterColon = extraData.substr(pos + 1);
                battery = stoi(afterColon);
                cout << "ID : " << id << ", Battery : " << battery << endl;
            }
        }
        else if (type == "HybridTruck")
        {
            int cargo, battery;
            size_t posColon1 = extraData.find(':');
            size_t posPipe = extraData.find('|');

            if(posColon1 == string::npos && posPipe == string::npos)
            {
                cout << "Colon (:) and Pipe (|) not found" << endl;
            }
            else
            {
                string cargoStr = extraData.substr(posColon1 + 1, posPipe - posColon1 -1 );
                cargo = stoi(cargoStr);
                
                size_t batteryLabelPos = extraData.find("Battery:");
                size_t posColon2 = extraData.find(':',batteryLabelPos);

                if(posColon2 == string::npos)
                {
                    cout << "Second Colon (:) not found" << endl;
                }
                else
                {
                    string batteryStr = extraData.substr(posColon2 + 1);
                    battery = stoi(batteryStr);
                }

                cout << "ID : " << id << ", Cargo Capacity : " << cargo << ", Battery : " << battery << endl;
            }

        }
        else
            cout << "ID : " << id << ", Type not found" << endl;
    
    }

    inpFile.close();
}