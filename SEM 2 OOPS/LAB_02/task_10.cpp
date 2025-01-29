#include<iostream>
using namespace std;

int main()
{
    int rows,cols;
    cout << "Enter Rows : ";
    cin >> rows;
    cout << "Enter Cols : ";
    cin >> cols;

    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    int **transpose = new int*[cols];
    for(int i = 0; i < cols; i++)
    {
        transpose[i] = new int[rows];
    }

    cout << "Enter Elements in the matrix "<<endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Element ("<<i+1<<","<<j+1<<") : ";
            cin >> *(*(matrix + i) + j);
        }
    }
    
    cout << "The Matrix : "<<endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            *(*(transpose + j) + i) = *(*(matrix + i) + j);
        }
    }

    cout << "The Transpose : "<<endl;
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            cout << *(*(transpose + i) + j) << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < cols; i++)
    {
        delete[] transpose[i];
    }
    delete[] transpose;
}