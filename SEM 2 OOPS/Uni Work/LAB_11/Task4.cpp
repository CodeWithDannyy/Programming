#include<iostream>
#include<exception>
#include<typeinfo>
#include<cmath>
using namespace std;

class NegativeNumberException : public exception
{
    public:
        const char* what() const noexcept override 
        {
            return "NegativeNumberException - Input must be Non-neagtive";
        }
};

class InvalidTypeException : public exception
{
    public:
        const char* what() const noexcept override 
        {
            return "InvalidTypeException - Non-numeric type detected";
        }
};

template <typename T>
T squareRoot(T num);

template<>
string squareRoot<string>(string num)
{
    throw InvalidTypeException();
}


template <typename T>
T squareRoot(T num)
{
    if(typeid(num) == typeid(string) || (typeid(num) != typeid(int) && typeid(num) != typeid(float) && typeid(num) != typeid(double) ))
    {
        throw InvalidTypeException();
    }
    
    if(num < 0)
    {
        throw NegativeNumberException();
    }
    
    return std::sqrt(num);
}   


int main()
{

    try
    {
        cout << "Square root of 9: " << squareRoot(9) << endl;
        cout << "Square root of -4: " << squareRoot(-4) << endl;
    }
    catch(const NegativeNumberException& e)
    {
        cerr << e.what() << endl;
    }
    catch(const InvalidTypeException& e)
    {
        cerr << e.what() << endl;
    }
    
    try 
    {
        cout << "Square root of \"hello\" : " << squareRoot(string("hello")) << endl;
    }
    catch(const NegativeNumberException& e)
    {
        cerr << e.what() << endl;
    }
    catch(const InvalidTypeException& e)
    {
        cerr << e.what() << endl;
    }
    
    return 0;
    
}