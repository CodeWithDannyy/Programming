#include<iostream>
using namespace std;

class Currency
{
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate;

    public:
        Currency(double amount, string currencyCode, string currencySymbol, double exchangeRate)
            : amount(amount), currencyCode(currencyCode), currencySymbol(currencySymbol), exchangeRate(exchangeRate) {}

        virtual double convertToBase()
        {
            return amount * exchangeRate;
        }

        virtual double convertTo(Currency *targetCurrency)
        {
            double amountInBase = convertToBase();
            return amountInBase/targetCurrency->exchangeRate;
        }

        virtual void displayCurrency()
        {
            cout << currencySymbol << " " << amount << " (" << currencyCode << ")" << endl;
        }
};

class Dollar : public Currency
{
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

        double convertToBase()
        {
            return amount;
        }
        
        void displayCurrency()
        {
            cout << currencySymbol << " " << amount << " (" << currencyCode << ")" << endl;
        }
};

class Euro : public Currency
{
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

        double convertToBase()
        {
            return amount * exchangeRate;
        }
        
        void displayCurrency()
        {
            cout << currencySymbol << " " << amount << " (" << currencyCode << ")" << endl;
        }
};

class Rupee : public Currency
{
    public:
        Rupee(double amt) : Currency(amt, "PKR", "Rs", 0.003569) {}

        double convertToBase()
        {
            return amount * exchangeRate;
        }

        void displayCurrency()
        {
            cout << currencySymbol << " " << amount << " (" << currencyCode << ")" << endl;
        }
};

int main()
{
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);

    Currency* currencies[3] = {&usd, &eur, &pkr};

    cout << "Original Currencies:" << endl;
    currencies[0]->displayCurrency();
    currencies[1]->displayCurrency();
    currencies[2]->displayCurrency();

    cout << "Currency Conversions : " << endl;
    cout << "100 USD To Pkr : " << currencies[0]->convertTo(&pkr) << endl;
    cout << "100 USD To Euro : " << currencies[0]->convertTo(&eur) << endl;
    cout << "50 Eur To USD : " << currencies[1]->convertTo(&usd) << endl;
    cout << "50 Eur To Pkr : " << currencies[1]->convertTo(&pkr) << endl;
    cout << "5000 Pkr To USD : " << currencies[2]->convertTo(&usd) << endl;
    cout << "5000 Pkr To Eur : " << currencies[2]->convertTo(&eur) << endl;

    return 0;
}