#include<iostream>
using namespace std;

class Currency
{
    int money;

    public:
        Currency(int money = 0): money(money) {}

        Currency operator-()
        {
            return Currency(-money);
        }
        Currency operator+(const Currency& object)
        {
            return Currency(money + object.money);
        }

        Currency operator-(const Currency& object)
        {
            return Currency(money - object.money);
        }

        Currency& operator+=(const Currency& object)
        {
            money += object.money;
            return *this;
        }

        Currency& operator-=(const Currency& object)
        {
            money -= object.money;
            return *this;
        }

        friend ostream& operator<<(ostream& os, const Currency& object);
};

ostream& operator<<(ostream& os, const Currency& object)
{
    os << object.money;
    return os;
}

int main()
{
    Currency c1(10), c2(20), c3;

    c3 = c1 + c2;
    cout << "c3 : " << c3 << endl;
    c3 = c2 - c1;
    cout << "c3 : " << c3 << endl;
    c3 = -c3;
    cout << "c3 : " << c3 << endl;
    c3 += c2;
    cout << "c3 : " << c3 << endl;
    c3 -= c1;
    cout << "c3 : " << c3 << endl;
    
    return 0;
}