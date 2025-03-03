#include<iostream>
using namespace std;

class Account
{
    int accountNumber;
    float balance;

    public:
        Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    void displayDetails()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account
{
    float interestRate;

    public:
        SavingsAccount(int accountNumber, float balance, float interestRate) 
            : Account(accountNumber, balance), interestRate(interestRate) {}

        void displayDetails()
        {
            Account::displayDetails();
            cout << "Interest Rate: " << interestRate << "%" << endl;
        }
};

class CheckingAccount : public Account
{
    float overdraftLimit;

    public:
        CheckingAccount(int accountNumber, float balance, float overdraftLimit) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

        void displayDetails()
        {
            Account::displayDetails();
            cout << "Overdraft Limit: $" << overdraftLimit << endl;
        }
};

int main()
{
    SavingsAccount savingsAccount(12345, 1000.0, 5.0);
    savingsAccount.displayDetails();

    cout << endl;
    CheckingAccount checkingAccount(67890, 500.0, 1000.0);
    checkingAccount.displayDetails();
}