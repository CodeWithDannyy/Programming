#include <iostream>
using namespace std;

class Patient
{
private:
    int ID;
    string name;
    string *testResults;

public:
    Patient(int ID, string name, string *testResults) : ID(ID), name(name), testResults(testResults) {}

    Patient(const Patient &obj)
    {
        ID = obj.ID;
        name = obj.name;
        testResults = new string[5];
        for (int i = 0; i < 5; i++)
            testResults[i] = obj.testResults[i];
    }

    void displayInfo()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Test Results: ";
        for (int i = 0; i < 5; i++)
            cout << testResults[i] << " ";
        cout << endl;
    }

    ~Patient()
    {
        delete[] testResults;
    }
};

int main()
{
    string testResults[] = {"Positive", "Negative", "Positive", "Negative", "Positive"};
    Patient patient1(1, "John Doe", testResults);
    Patient patient2(patient1);

    patient1.displayInfo();
    patient2.displayInfo();
    return 0;
}