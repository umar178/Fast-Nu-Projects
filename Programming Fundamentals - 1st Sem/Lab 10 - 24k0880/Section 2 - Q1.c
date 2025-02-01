#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 5

typedef struct {
    int flightNumber;
    char departureCity[30];
    char destinationCity[30];
    char date[15];
    int availableSeats;
} Flight;


void displayFlightDetails(Flight flights[], int count) {
    printf("\nFlight Details:\n");
    for (int i = 0; i < count; i++) {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Departure City: %s\n", flights[i].departureCity);
        printf("Destination City: %s\n", flights[i].destinationCity);
        printf("Date: %s\n", flights[i].date);
        printf("Available Seats: %d\n\n", flights[i].availableSeats);
    }
}

void bookSeat(Flight flights[], int count) {
    int flightNumber;
    printf("Enter the flight number to book a seat: ");
    scanf("%d", &flightNumber);

    for (int i = 0; i < count; i++) {
        if (flights[i].flightNumber == flightNumber) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully! Remaining seats: %d\n", flights[i].availableSeats);
            } else {
                printf("No seats available for this flight.\n");
            }
            return;
        }
    }
    printf("Flight not found!\n");
}


int main() {
    Flight flights[MAX_FLIGHTS] = {
        {101, "New York", "Los Angeles", "2024-12-01", 100},
        {102, "Chicago", "Moscow", "2024-12-02", 50},
        {103, "Karachi", "Islamabad", "2024-12-03", 20},
        {104, "Lahore", "Karachi", "2024-12-04", 0},
        {105, "Delhi", "London", "2024-12-05", 30}
    };

    int choice;
    do {
        printf("\nFlight Management System\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlightDetails(flights, MAX_FLIGHTS);
                break;
            case 2:
                bookSeat(flights, MAX_FLIGHTS);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}