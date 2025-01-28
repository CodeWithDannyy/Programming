#include<iostream>
using namespace std;

int main()
{
    int AQI[4][7] = {
        {130, 148, 139, 130, 116, 122, 140}, 
        {120, 180, 240, 300, 360, 420, 480}, 
        {80, 130, 180, 230, 280, 330, 380},  
        {90, 140, 190, 240, 290, 340, 390}  
    };

    //task 1
    float cityAvg[4];
    for(int i = 0; i < 4; i++)
    {
        int sum = 0;
        cityAvg[i] = 0.0;
        for(int j = 0; j < 7;j++)
        {
            sum += AQI[i][j];
        }
        cityAvg[i] = (float)sum/7;
    }

    int largestAqiAvg = cityAvg[0];
    int worstCity;
    for(int i = 0; i < 4; i++)
    {
        if(cityAvg[i] > largestAqiAvg)
        {
            largestAqiAvg = cityAvg[i];
            worstCity = i+1;
        }
    }

    cout << "Weekly Average city wise : "<<endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "City "<<i+1<<" : "<<cityAvg[i]<<endl;
    }

    cout << "City " << worstCity << " is the worst AQI of "<<largestAqiAvg<<endl;

    //task 2
    cout << "\nCritical Polution Days for each city"<<endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(AQI[i][j] >= 150)
            {
                switch (j)
                {
                case 0:
                    cout << "City "<<i+1 << " , Day : Monday"<<endl;
                    break;
                
                case 1:
                    cout << "City "<<i+1 << " , Day : Tuesday"<<endl;
                    break;
                
                case 2:
                    cout << "City "<<i+1 << " , Day : Wednesday"<<endl;
                    break;
                
                case 3:
                    cout << "City "<<i+1 << " , Day : Thursday"<<endl;
                    break;
                
                case 4:
                    cout << "City "<<i+1 << " , Day : Friday"<<endl;
                    break;
                
                case 5:
                    cout << "City "<<i+1 << " , Day : Saturday"<<endl;
                    break;
                
                case 6:
                    cout << "City "<<i+1 << " , Day : Sunday"<<endl;
                    break;
                
                default:
                    cout << "Wrong Day"<<endl;
                    break;
                }
            }
        }
    }

    //task 3
    cout << "\nCharts of AQI for each city"<<endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "City "<<i+1<<" : "<<endl;
        for(int j = 0; j < 7; j++)
        {
            cout << "Day "<<j+1<<" : ";
            int symbols = AQI[i][j] / 50; 
            for(int i = 0; i < symbols; i++)
            {
                cout<<"*";
            }
            cout << endl;
        }
        cout << endl;
    }

    //task 4
    int aqi[4][28] = {
        {130, 148, 139, 130, 116, 122, 140, 120, 128, 135, 138, 125, 130, 145, 110, 125, 135, 130, 140, 125, 118, 112, 115, 120, 125, 140, 130, 120}, 
        {120, 180, 240, 300, 360, 420, 480, 400, 380, 300, 280, 270, 260, 250, 240, 230, 220, 210, 200, 190, 180, 170, 160, 150, 140, 130, 120, 110}, 
        {80, 130, 180, 230, 280, 330, 380, 360, 340, 320, 300, 280, 260, 240, 220, 200, 180, 160, 140, 120, 100, 90, 80, 70, 60, 50, 40, 30},  
        {90, 140, 190, 240, 290, 340, 390, 370, 350, 330, 310, 290, 270, 250, 230, 210, 190, 170, 150, 130, 110, 100, 90, 80, 70, 60, 50, 40}  
    };

    float monthlyAvg[4];
    for(int i = 0; i < 4; i++)
    {
        int sum = 0;
        monthlyAvg[i] = 0.0;
        for(int j = 0; j < 28; j++)
        {
            sum += aqi[i][j];
        }
        monthlyAvg[i] = (float)sum/28;
    }
    cout << "\nMonthly City Avg"<<endl;
    for(int i = 0; i < 4; i++)
    {
        cout << "City "<<i+1<<" : "<<monthlyAvg[i]<<endl;
    }

    int improvements[4];
    for(int i = 0; i < 4; i++)
    {
        int firstWeekSum = 0, lastWeekSum = 0;
        for(int j = 0; j < 7; j++)
        {
            firstWeekSum += aqi[i][j];
            lastWeekSum += aqi[i][j+21];
        }
        improvements[i] = (firstWeekSum / 7) - (lastWeekSum / 7);
    }

    int improvement = improvements[0], bestCity ;
    for(int i = 0; i < 4; i++)
    {
        if(improvements[i] > improvement)
        {
            improvement = improvements[i];
            bestCity = i+1;
        }
    }

    cout << "City "<< bestCity<<" improved the most by "<<improvement<<endl;

    //task 5
    cout << "\n -------REPORT-------"<<endl;

    cout << "Weekly Average city wise : "<<endl;   //already done above
    for(int i = 0; i < 4; i++)
    {
        cout << "City "<<i+1<<" : "<<cityAvg[i]<<endl;
    }

    cout << "\nCritical Polution Days for each city"<<endl;   //already done above
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(AQI[i][j] >= 150)
            {
                switch (j)
                {
                case 0:
                    cout << "City "<<i+1 << " , Day : Monday"<<endl;
                    break;
                
                case 1:
                    cout << "City "<<i+1 << " , Day : Tuesday"<<endl;
                    break;
                
                case 2:
                    cout << "City "<<i+1 << " , Day : Wednesday"<<endl;
                    break;
                
                case 3:
                    cout << "City "<<i+1 << " , Day : Thursday"<<endl;
                    break;
                
                case 4:
                    cout << "City "<<i+1 << " , Day : Friday"<<endl;
                    break;
                
                case 5:
                    cout << "City "<<i+1 << " , Day : Saturday"<<endl;
                    break;
                
                case 6:
                    cout << "City "<<i+1 << " , Day : Sunday"<<endl;
                    break;
                
                default:
                    cout << "Wrong Day"<<endl;
                    break;
                }
            }
        }
    }

    cout << "\n Highest and Lowest AQI values for each city"<<endl;
    for(int i = 0; i < 4; i++)
    {
        int highest = aqi[i][0];
        int lowest = aqi[i][0];
        for(int j = 0; j < 28; j++)
        {
            if(aqi[i][j] > highest)
            {
                highest = aqi[i][j];
            }
            if(aqi[i][j] < lowest)
            {
                lowest = aqi[i][j];
            }
        }
        cout << "City "<<i+1 << " , highest AQI: "<<highest << " , Lowest AQI: "<<lowest<<endl;
    }
}