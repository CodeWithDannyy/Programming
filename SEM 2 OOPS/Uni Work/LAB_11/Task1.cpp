#include<iostream>
using namespace std;

class InvalidValueException : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "InvalidValueException - Age cannot be negative or exceed 120";
        }
};

void validateAge(int age)
{
    if(age <= 0 || age >= 120)
        throw InvalidValueException();
}

int main()
{
    int age;
    cout << "Enter Age : " ;
    cin >> age;
    try
    {
        validateAge(age);
        cout << "Age is Valid.";
    }
    catch(const InvalidValueException& e)
    {
        cout << "Error : " << e.what() << endl;
    }
}

