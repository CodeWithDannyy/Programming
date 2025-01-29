#include<iostream>
using namespace std;

int main()
{
    int size;

    cout << "Enter size of an array : ";
    cin >> size;

    int * arr = new int[size];

    cout << "Enter "<< size <<" Elements in array"<<endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter Element "<<i+1<<" : ";
        cin >> arr[i];
    }

    int sum = 0, largest = arr[0];
    float avg;
    for(int i = 0 ; i < size; i++)
    {
        sum += arr[i];
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    avg = (float)sum/size;
    cout << "Sum : "<<sum<<endl;
    cout << "Average : "<<avg<<endl;
    cout << "Largest Number : "<<largest<<endl;

    delete[] arr;

    return 0;
}