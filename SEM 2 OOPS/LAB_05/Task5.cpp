#include<iostream>
using namespace std;

class tourGuide
{
    private:
        string name;
        int yearOfExperience;
        string specialization;

    public:
        tourGuide(string name, int yearOfExperience, string specialization) : name(name), yearOfExperience(yearOfExperience), specialization(specialization) {}

        void displayGuideDetails()
        {
            cout << "Name: " << name << endl;
            cout << "Year of Experience: " << yearOfExperience << endl;
            cout << "Specialization: " << specialization << endl;
            cout << endl;
        }

};

class TravelAgency
{
    private:
        string agencyName;
        tourGuide **tourGuides;
        int guideCount;
        int maxGuides;

    public:
        TravelAgency(string agencyName, int maxGuides) : agencyName(agencyName), guideCount(0), maxGuides(maxGuides)
        {
            tourGuides = new tourGuide*[maxGuides];
        }

        void addTourGuide(tourGuide* tourGuide)
        {
            if(guideCount < maxGuides)
            {
                tourGuides[guideCount++] = tourGuide;
            }
            else
                cout << "Can't add more tour guides" << endl;
        }

        void displayAgencyDetails()
        {
            cout << "Agency Name: " << agencyName << endl;
            cout << "Number of Tour Guides: " << guideCount << endl;
            
            cout << "Tour Guides:" << endl;
            for(int i = 0; i < guideCount; i++)
            {
                cout << "Tour Guide " << i+1 << endl;
                tourGuides[i]->displayGuideDetails();
            }
        }

        ~TravelAgency()
        {
            for(int i = 0; i < guideCount; i++)
                delete tourGuides[i];
            delete[] tourGuides;
        }
};

int main()
{
    tourGuide t1("Alice", 3, "Walking City Tours");
    tourGuide t2("Bob", 5, "Historical Tours");
    tourGuide t3("Charlie", 2, "Beach Tours");
    TravelAgency agency("XYZ Tours", 3);   
    
    agency.addTourGuide(&t1);
    agency.addTourGuide(&t2);
    agency.addTourGuide(&t3);

    agency.displayAgencyDetails();
    
    return 0;
}