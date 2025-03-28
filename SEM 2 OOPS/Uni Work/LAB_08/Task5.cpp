#include<iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

    public:
        Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator)
        {
            if(denominator == 0)
            {
                cout << "Error: Denominator Cannot be zero" << endl;
                exit(1);
            }
        }

        Fraction operator+(const Fraction& object) const
        {
            return Fraction(numerator * object.denominator + object.numerator * denominator, denominator * object.denominator);
        }

        Fraction operator-(const Fraction& object) const
        {
            return Fraction(numerator * object.denominator - object.numerator * denominator, denominator * object.denominator);
        }

        Fraction operator*(const Fraction &other) const
        {
            return Fraction(numerator * other.numerator, denominator * other.denominator);
        }

        Fraction operator/(const Fraction &other) const
        {
            if(other.numerator == 0)
            {
                cout << "Zero Division Error" << endl;
                exit(1);
            }

            return Fraction(numerator * other.denominator, denominator * other.numerator);
        }

        friend ostream& operator<<(ostream& os, const Fraction& object)
        {
            os << object.numerator << "/" << object.denominator;
            return os;
        }
};

int main()
{
    Fraction f1(3, 4);
    Fraction f2(2, 5);

    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;

    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    return 0;
}