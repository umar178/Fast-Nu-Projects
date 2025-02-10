#include <iostream>
#include <string>
using namespace std;

class Movie {
    string movieName;
    int availableSeats;
    double ticketPrice;
public:
    Movie(string name = "Avengers", int seats = 50, double price = 10.0) : movieName(name), availableSeats(seats), ticketPrice(price) {
        cout << "Movie: " << movieName << " is now available for booking!" << endl;
    }
    ~Movie() { 
		cout << "Movie booking closed: " << movieName << endl; 
	}
	
    void bookTicket(int seats) {
        availableSeats -= seats;
        cout << seats << " tickets booked for " << movieName << " | Remaining Seats: " << availableSeats << endl;
    }
    
    void displayMovieInfo() {
        cout << "Movie: " << movieName << " | Available Seats: " << availableSeats << " | Ticket Price: $" << ticketPrice << endl;
    }
};

int main() {
    Movie movie;
    movie.displayMovieInfo();
    movie.bookTicket(5);
    movie.displayMovieInfo();
}
