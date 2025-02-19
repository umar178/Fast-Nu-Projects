#include <iostream>
using namespace std;

class Movie {
public:
    string title;
    int duration;
    
    Movie(string t, int d) : title(t), duration(d) {}

    void display() {
        cout << "Movie: " << title << " | Duration: " << duration << " minutes" << endl;
    }
};

class Cinema {
private:
    Movie* movies[3];
    int count;

public:
    Cinema() : count(0) {}

    void addMovie(Movie* movie) {
        if (count < 3) {
            movies[count++] = movie;
        }
    }

    void displayMovies() {
        cout << "Currently Showing Movies:\n";
        for (int i = 0; i < count; i++) {
            movies[i]->display();
        }
    }
};

int main() {
    Movie m1("Inception", 148), m2("Titanic", 195), m3("The Dark Knight", 152);
    Cinema cinema;
    cinema.addMovie(&m1);
    cinema.addMovie(&m2);
    cinema.addMovie(&m3);
    cinema.displayMovies();
    return 0;
}

