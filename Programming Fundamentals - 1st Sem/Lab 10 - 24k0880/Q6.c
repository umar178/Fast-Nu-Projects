#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 10

typedef struct {
    char name[30];
    char destination[30];
    float cost;
    int seats;
} Package;

void displayPackages(Package packages[], int count);
void bookPackage(Package packages[], int count);

int main() {
    Package packages[MAX_PACKAGES] = {
        {"Xbox", "Maldives", 1200, 10},
        {"PS4", "Himalayas", 800, 5},
    };
    int packageCount = 2;

    int choice;
    do {
        printf("\nTravel Package System\n");
        printf("1. Display Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
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

void displayPackages(Package packages[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Destination: %s, Cost: %.2f, Seats: %d\n",
               packages[i].name, packages[i].destination, packages[i].cost, packages[i].seats);
    }
}

void bookPackage(Package packages[], int count) {
    char name[30];
    printf("Enter package name to book: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(packages[i].name, name) == 0) {
            if (packages[i].seats > 0) {
                packages[i].seats--;
                printf("Package booked successfully! Remaining seats: %d\n", packages[i].seats);
                return;
            } else {
                printf("No seats available!\n");
                return;
            }
        }
    }
    printf("Package not found!\n");
}
