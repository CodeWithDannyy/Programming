#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reversedArray(int *arr, int size)
{
    int *start = arr;
    int *end = arr + size - 1;

    while(start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
int main()
{
    int a = 5, b = 6;
    swap(&a,&b);
    cout << "a : "<<a << "\nb : "<<b<<endl;

    int size;
    cout << "Enter Array Size : ";
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element "<< i+1 << " : ";
        cin >> arr[i];
    }

    reversedArray(arr,size);

    cout << "Reversed Array "<<endl; 
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    delete[] arr;

    return 0;
}