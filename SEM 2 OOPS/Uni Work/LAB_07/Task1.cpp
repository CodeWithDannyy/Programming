#include<iostream>
using namespace std;

class Account
{
    protected:
        int accountNumber;
        double balance;
        string accountHolderName;
        string accountType;

    public:
    Account(int accountNumber, double balance, string accountHolderName, string accountType)
    : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName), accountType(accountType) {}

    void deposit(double amount)
    {
        cout << "Current Balance : " << balance << endl; 
        balance += amount;
        cout << "Amount Deposited : " << amount << endl;
        cout << "Updated Balance : " << balance << endl;
    }

    virtual void withdraw(double amount)
    {
        cout << "Current Balance : " << balance << endl; 
        if(balance < amount)
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount Withdrawn : " << amount << endl;
        cout << "Updated Balance : " << balance << endl;
    }

    virtual void calculateInterest()
    {   
        cout << "Interest Rate is not defined" << endl;
    }

    virtual void printStatement()
    {
        cout << "Interest Rate is not definfed in base Account Class" << endl;
    }

    void getAccountInfo()
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Name : " << accountHolderName << endl;
        cout << "Balance : " << balance <<endl;
    }


};

class SavingsAccount : public Account
{
    double interestRate;
    double minimumBalance;

    public:
    SavingsAccount(int accountNumber, double balance, string accountHolderName, string accountType, double interestRate, double minimumBalance)
    : Account(accountNumber, balance, accountHolderName, accountType), interestRate(interestRate), minimumBalance(minimumBalance) {}

    void calculateInterest()
    {
        double interest = balance * (interestRate/100);
        cout << "Interest : " << interest << endl;
    }

    void printStatement()
    {
        cout << "Interest Rate : " << interestRate << endl;
    }

    void withdraw(double amount)
    {
        cout << "Current Balance : " << balance << endl; 
        if((balance - amount) < minimumBalance)
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount Withdrawn : " << amount << endl;
        cout << "Updated Balance : " << balance << endl;
    }

};

class CheckingAccount : public Account
{
    public:
    CheckingAccount(int accountNumber, double balance, string accountHolderName, string accountType, double interestRate, double minimumBalance)
    : Account(accountNumber, balance, accountHolderName, accountType) {}

    void withdraw(double amount)
    {
        cout << "Current Balance : " << balance << endl; 
        if(balance < amount)
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount Withdrawn : " << amount << endl;
        cout << "Updated Balance : " << balance << endl;
    }
};

class FixedDepositAccount : public Account
{
    string maturityDate;
    double fixedInterestRate;

    public:
    FixedDepositAccount(int accountNumber, double balance, string accountHolderName, string accountType, double interestRate, double minimumBalance, string maturityDate, double fixedInterestRate)
    : Account(accountNumber, balance, accountHolderName, accountType), maturityDate(maturityDate), fixedInterestRate(fixedInterestRate) {}

    void withdraw(double amount)
    {
        cout << "Current Balance : " << balance << endl; 
        if(balance < amount)
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount Withdrawn : " << amount << endl;
        cout << "Updated Balance : " << balance << endl;
    }

    void calculateInterest()
    {
        double interest = balance * (fixedInterestRate/100);
        cout << "Interest : " << interest << endl;
    }

    void printStatement()
    {
        cout << "Interest Rate : " << fixedInterestRate << endl;
    }
};

int main()
{
    SavingsAccount savingsAcc(101, 5000.0, "John Doe", "Savings", 5.0, 1000.0);
    CheckingAccount checkingAcc(102, 2000.0, "Jane Smith", "Checking", 0.0, 0.0);
    FixedDepositAccount fdAcc(103, 10000.0, "Alice Brown", "Fixed Deposit", 0.0, 0.0, "2026-03-17", 7.0);

    Account* accounts[3];
    accounts[0] = &savingsAcc;
    accounts[1] = &checkingAcc;
    accounts[2] = &fdAcc;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nAccount " << i + 1 << " Information:" << endl;
        accounts[i]->getAccountInfo();
        accounts[i]->deposit(500);
        accounts[i]->withdraw(300); 
        accounts[i]->calculateInterest(); 
        accounts[i]->printStatement(); 
    }

    return 0;
}