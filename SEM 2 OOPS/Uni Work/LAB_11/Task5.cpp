#include<iostream>
using namespace std;

class InsufficientFundsException
{
    double deficit;
    public:
        InsufficientFundsException(double deficit) : deficit(deficit) {}

        double getDeficit() const
        {
            return deficit;
        }
};

template<typename T>
class BankAccount
{
    T balance;
    public:
        BankAccount(T balance) : balance(balance) {}
    
        void withdraw(T amount)
        {
            if(amount > balance)
            {
                throw InsufficientFundsException(amount - balance);
            }
            else
            {
                balance -= amount;
                cout << "Withdrawal successful. Remaining Balance: " << balance << endl;
            }
        }

        T getBalance() const
        {
            return balance;
        }
};

int main()
{
    BankAccount<double> account(500.00);

    cout << "Balance: $" << account.getBalance() << endl;

    try
    {
        account.withdraw(600.00);
    }
    catch(const InsufficientFundsException& e)
    {
        cout << "Withdraw $600: InsufficientFundsException - Deficit: $" << e.getDeficit() << endl;
    }

    return 0;
}
