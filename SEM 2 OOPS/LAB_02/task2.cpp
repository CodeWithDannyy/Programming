#include<iostream>
using namespace std;

int main()
{
    int rows1,cols1;
    int rows2,cols2;

    cout << "Enter number of rows for Matrix 1: ";
    cin >> rows1;
    cout << "Enter number of cols for Matrix 1: ";
    cin >> cols1;

    cout << "Enter number of rows for Matrix 2: ";
    cin >> rows2;
    cout << "Enter number of cols for Matrix 2: ";
    cin >> cols2;

    int **matrix1 = new int*[rows1];
    for(int i = 0; i < rows1; i++)
    {
        matrix1[i] = new int[cols1];
    }

    int **matrix2 = new int*[rows2];
    for(int i = 0; i < rows2; i++)
    {
        matrix2[i] = new int[cols2];
    }

    cout << "\nEnter Elements for Matrix 1"<<endl;
    for(int i = 0; i < rows1; i++)
    {
        for(int j = 0; j < cols1; j++)
        {
            cout <<"Element ("<<i+1<<","<<j+1<<") : ";
            cin >> matrix1[i][j];
        }
    }

    cout << "\nEnter Elements for Matrix 1"<<endl;
    for(int i = 0; i < rows2; i++)
    {
        for(int j = 0; j < cols2; j++)
        {
            cout <<"Element ("<<i+1<<","<<j+1<<") : ";
            cin >> matrix2[i][j];
        }
    }

    if(rows1 == rows2 && cols1 == cols2)
    {
        int matrixSum[rows1][cols1], matrixDiff[rows1][cols1];
        for(int i = 0; i < rows2; i++)
        {
            for(int j = 0; j < cols2; j++)
            {
                matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        cout << "\nMatrix Sum "<<endl;
        for(int i = 0; i < rows2; i++)
        {
            for(int j = 0; j < cols2; j++)
            {
                cout << matrixSum[i][j] << " ";
            }
            cout <<endl;
        }

        for(int i = 0; i < rows2; i++)
        {
            for(int j = 0; j < cols2; j++)
            {
                matrixDiff[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        cout << "\nMatrix Subtraction "<<endl;
        for(int i = 0; i < rows2; i++)
        {
            for(int j = 0; j < cols2; j++)
            {
                cout << matrixDiff[i][j] << " ";
            }
            cout <<endl;
        }
    }
    else
    {
        cout << "Matrix addition and subtraction is not possible"<<endl;
        return 0;
    }
}