#include<iostream>
using namespace std;

class Media
{
    protected:
        string title;
        string publicationDate;
        int uniqueID;
        string publisher;

    public:
        Media(string title, string publicationDate, int uniqueID, string publisher)
            : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher) {}

        virtual void displayInfo()
        {
            cout << "Title : " << title << endl;
            cout << "ID : " << uniqueID << endl;
            cout << "Publication Date : " << publicationDate << endl;
            cout << "Publisher : " << publisher << endl;
        }

        void checkOut()
        {
            cout << "Checking out...." << endl;
        }

        void returnItem()
        {
            cout << "Returning Item...." << endl;
        }

        string getTitle() const { return title; }
        string getPublisher() const { return publisher; }
        int getUniqueID() const { return uniqueID; }
};

class Book : public Media
{
    string author;
    string ISBN;
    int numberOfPages;

    public:
        Book(string title, string publicationDate, int uniqueID, string publisher, string author, string ISBN, int numberOfPages)
            : Media(title, publicationDate, uniqueID, publisher), author(author), ISBN(ISBN), numberOfPages(numberOfPages) {}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Author : " << author << endl;
            cout << "ISBN : " << ISBN << endl;
            cout << "Number Of Pages : " << numberOfPages << endl;
        }
};

class DVD : public Media
{
    string director;
    int duration;
    string rating;

    public:
        DVD(string title, string publicationDate, int uniqueID, string publisher, string director, int duration, string rating)
            : Media(title, publicationDate, uniqueID, publisher), director(director), duration(duration), rating(rating) {}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Director : " << director << endl;
            cout << "Duration : " << duration << endl;
            cout << "Rating : " << rating << endl;
        }

};

class CD : public Media
{
    string artist;
    string genre;
    int numberOfTracks;

    public:
        CD(string title, string publicationDate, int uniqueID, string publisher, string artist, string genre, int tracks)
            : Media(title, publicationDate, uniqueID, publisher), artist(artist), genre(genre), numberOfTracks(tracks) {}

        void displayInfo()
        {
            Media::displayInfo();
            cout << "Artist : " << artist << endl;
            cout << "Genre : " << genre << endl;
            cout << "Number of Tracks : " << numberOfTracks << endl;
        }
};

class Magazine : public Media
{
    public:
        Magazine(string title, string publicationDate, int uniqueID, string publisher)
            : Media(title, publicationDate, uniqueID, publisher) {}

        void displayInfo()
        {
            Media::displayInfo();
        }
};

void searchMedia(Media* items[], int size, string title, char temp)
{
    for(int i = 0; i < size; i++)
    {
        if (items[i]->getTitle() == title)
        {
            items[i]->displayInfo();
        }
    }
}

void searchMedia(Media* items[], int size, string publisher)
{
    for(int i = 0; i < size; i++)
    {
        if (items[i]->getPublisher() == publisher)
        {
            items[i]->displayInfo();
        }
    }
}

void searchMedia(Media* items[], int size, int uniqueID)
{
    for(int i = 0; i < size; i++)
    {
        if (items[i]->getUniqueID() == uniqueID)
        {
            items[i]->displayInfo();
        }
    }
}

int main()
{
    Book book("The C++ Programming Language", "2013", 1001, "Addison-Wesley", "Bjarne Stroustrup", "9780321563842", 1376);
    DVD dvd("Inception", "2010", 1002, "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD cd("Thriller", "1982", 1003, "Epic Records", "Michael Jackson", "Pop", 9);
    Magazine magazine("National Geographic", "2023", 1004, "NatGeo");

    Media* media[4] = { &book, &dvd, &cd, &magazine};

    for(int i = 0; i < 4; i++)
    {
        media[i]->displayInfo();
        cout << "------------------"<< endl;
    }

    media[0]->checkOut();
    media[0]->returnItem();
    cout << endl;


    searchMedia(media, 4, "Inception", 't');
    cout << endl;

    searchMedia(media, 4, "Epic Records");
    cout << endl;

    searchMedia(media, 4, 1001);
    cout << endl;

    return 0;
}