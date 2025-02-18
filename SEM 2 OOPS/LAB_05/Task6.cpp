#include<iostream>
using namespace std;

class Movie
{
    private:
        string title;
        string director;
        int duration;

    public:
        Movie() {}
        Movie(string title, string director, int duration) : title(title), director(director), duration(duration) {}

        void displayDetails()
        {
            cout << "Title: " << title << endl;
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << " minutes" << endl;
        }

};

class CinemaHall
{
    private:
        string name;
        int seats;
        Movie movies[3];

    public:
        CinemaHall(string name, int seats, Movie movieList[]) : name(name), seats(seats)
        {
            for(int i = 0; i < 3; i++)
            {
                movies[i] = movieList[i];
            }
        }

        void displayDetails()
        {
            cout << "Cinema Hall Name: " << name << endl;
            cout << "Number of Seats: " << seats << endl << endl;
            cout << "Movies playing: " << endl;
            for(int i = 0; i < 3; i++)
            {
                movies[i].displayDetails();
                cout << "----------------------" << endl;
            }
        }
};

int main()
{
    Movie movieList[3] = {
        Movie("Inception", "Christopher Nolan", 148),
        Movie("Interstellar", "Christopher Nolan", 169),
        Movie("The Dark Knight", "Christopher Nolan", 152)
    };

    CinemaHall myCinema("IMAX Theater", 250, movieList);

    myCinema.displayDetails();

    return 0;
}
