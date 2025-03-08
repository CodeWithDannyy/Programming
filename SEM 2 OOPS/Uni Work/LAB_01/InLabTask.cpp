#include<iostream>
#include<string>
using namespace std;

int main(){
    const int maxParticipants = 5;
    int participants1, participants2;

    cout << "Enter number of participant for event 1 : ";
    cin >> participants1;

    if(participants1 > maxParticipants)
    {
        cout << "Not more than five participants"<<endl;
        return 0;
    }
    cout << "Enter number of participant for event 2 : ";
    cin >> participants2;

    if(participants2 > maxParticipants)
    {
        cout << "Not more than five participants"<<endl;
        return 0;
    }

    string event1Name[maxParticipants];
    string event2Name[maxParticipants];

    cin.ignore();

    //task 1
    cout << "Enter "<< participants1 <<" Participant Names for Event 1"<<endl;
    for(int i = 0; i < participants1; i++){
        cout<<"Enter Name for Participant "<< i+1 <<" : ";
        getline(cin,event1Name[i]);
    }

    cout << "Enter "<< participants2 <<" Participant Names for Event 2"<<endl;
    for(int i = 0; i < participants2; i++){
        cout<<"Enter Name for Participant "<< i+1 <<" : ";
        getline(cin,event2Name[i]);
    }

    //task 2
    bool found = false;
    string nameChecker;
    cout << "Enter Name to check if the participant is present or not : ";
    getline(cin,nameChecker);

    for(int i = 0; i < maxParticipants; i++)
    {
        if(nameChecker == event1Name[i] || nameChecker == event2Name[i]){
            cout << nameChecker << " is Present"<<endl;
            found = true;
        }
    }

    if(!found)
    {
        cout<< nameChecker << " is not present" << endl;
    }

    //task 3
    int totalSum;
    totalSum = (participants1 * 10) + (participants2 * 10);

    cout << "\nTotal Donations gathered from both events : "<< totalSum << endl;

    //task 4
    cout << "\nReversed Names of Participants for Event 1"<<endl;
    for(int i = 0; i < participants1; i++){
        for(int j = event1Name[i].length() - 1; j>=0;j--){
            cout << event1Name[i][j];
        }
        cout << endl;
    }

    cout << "\nReversed Names of Participants for Event 2"<<endl;
    for(int i = 0; i < participants2; i++){
        for(int j = event2Name[i].length() - 1; j>=0;j--){
            cout << event2Name[i][j];
        }
        cout << endl;
    }

    //task 5
    cout << "\nBar Chart" << endl;
    cout << "Event 1: ";
    for (int i = 0; i < participants1; i++) {
        cout << "*";
    }
    cout << "\nEvent 2: ";
    for (int i = 0; i < participants2; i++) {
        cout << "*";
    }
    return 0;
}