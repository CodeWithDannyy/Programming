#include<iostream>
using namespace std;

class StackOverflowException : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "StackOverflowException - Stack is full!";
        }
};

class StackUnderflowException : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "StackUnderflowException - Stack is empty!";
        }
};

template <typename T>
class Stack
{
    static const int capacity = 5;
    T arr[capacity];
    int top;

    public:
        Stack() : top(-1) {}

        void push(T value)
        {
            if(top >= capacity - 1)
                throw StackOverflowException();
            arr[++top] = value;
        }

        T pop()
        {
            if(top < 0)
                throw StackUnderflowException();
            return arr[top--];
        }
};

int main()
{
    Stack<int> s;

    try
    {
        for(int i = 0; i < 6; i++)
        {
            cout << "Pushing " << i << endl;
            s.push(i);
        }
    }
    catch(const StackOverflowException& e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        for(int i = 0; i < 6; i++)
        {
            cout << "Popped : " << s.pop() << endl;
        }
    }
    catch(const StackUnderflowException& e)
    {
        cerr << e.what() << endl;
    }
    
}