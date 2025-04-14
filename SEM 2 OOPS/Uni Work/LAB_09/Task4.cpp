#include <iostream>
using namespace std;

class PaymentMethod
{
    public:
        virtual bool processPayment(double amount) = 0;
        virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod 
{
    string cardNumber;

    public:
        CreditCard(string number) : cardNumber(number) {}

        bool processPayment(double amount) 
        {
            cout << "Processing credit card payment of " << amount << endl;
            if (cardNumber.length() == 16) 
            {
                cout << "Payment approved using Credit Card: " << cardNumber << endl;
                return true;
            } 
            else 
            {
                cout << "Invalid card number. Payment failed.\n";
                return false;
            }
        }
};

class DigitalWallet : public PaymentMethod 
{
    double balance;

    public:
        DigitalWallet(double initialBalance) : balance(initialBalance) {}

        bool processPayment(double amount) 
        {
            cout << "Processing digital wallet payment of " << amount << endl;
            if (balance >= amount) 
            {
                balance -= amount;
                cout << "Payment approved. Remaining wallet balance: " << balance << endl;
                return true;
            } 
            else 
            {
                cout << "Insufficient balance in Digital Wallet. Payment failed." << endl;
                return false;
            }
        }

        double getBalance() const 
        {
            return balance;
        }
};

int main() 
{
    CreditCard Card("1234567890123456");
    DigitalWallet Wallet(100.0);

    PaymentMethod* payment;

    payment = &Card;
    payment->processPayment(50.0);
    cout << endl;

    payment = &Wallet;
    payment->processPayment(30.0);
    cout << endl;

    payment->processPayment(80.0);

    return 0;
}
