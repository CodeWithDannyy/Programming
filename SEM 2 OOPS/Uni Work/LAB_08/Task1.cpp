#include<iostream>
using namespace std;

class Humidity;

class Temperature
{
    float temp;

    public:
        Temperature(float temp) : temp(temp) {}

        friend float calculateHeatIndex(Temperature t, Humidity h);
};

class Humidity
{
    float humidity;

    public:
        Humidity(float humidity) : humidity(humidity) {}

        friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t, Humidity h)
{
    float HI = -42.379 + 2.04901523 * t.temp + 10.14333127 * (h.humidity/100.0) - 0.22475541 * t.temp * (h.humidity/100.0);
    return HI;
}

int main()
{
    Temperature t(32.0);
    Humidity h(75);

    float HeatIndex = calculateHeatIndex(t, h);
    cout << "Heat Index : " << HeatIndex << endl;
}