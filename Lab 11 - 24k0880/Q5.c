#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 1000
#define MAX_LINE 256

// Define the Passenger structure
struct Passenger {
    int passengerId;
    int survived;
    int pclass;
    char name[100];
    char sex[10];
    float age;
    int sibsp;
    int parch;
    char ticket[20];
    float fare;
    char cabin[20];
    char embarked[2];
};

// Global array to hold passengers
struct Passenger passengers[MAX_PASSENGERS];
int passengerCount = 0;

// Function to load the dataset
void loadDataset(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE];
    fgets(line, sizeof(line), file); // Skip header line

    while (fgets(line, sizeof(line), file)) {
        struct Passenger p = {0};
        char *token = strtok(line, ",");

        p.passengerId = atoi(token); token = strtok(NULL, ",");
        p.survived = atoi(token); token = strtok(NULL, ",");
        p.pclass = atoi(token); token = strtok(NULL, ",");
        strcpy(p.name, token); token = strtok(NULL, ",");
        strcpy(p.sex, token); token = strtok(NULL, ",");
        p.age = atof(token); token = strtok(NULL, ",");
        p.sibsp = atoi(token); token = strtok(NULL, ",");
        p.parch = atoi(token); token = strtok(NULL, ",");
        strcpy(p.ticket, token); token = strtok(NULL, ",");
        p.fare = atof(token); token = strtok(NULL, ",");
        if (token != NULL) strcpy(p.cabin, token); token = strtok(NULL, ",");
        if (token != NULL) strcpy(p.embarked, token);

        passengers[passengerCount++] = p;
    }

    fclose(file);
}

// Function to calculate the average age of all passengers
float calculateAverageAge() {
    float totalAge = 0.0;
    int count = 0;

    for (int i = 0; i < passengerCount; i++) {
        if (passengers[i].age > 0) {
            totalAge += passengers[i].age;
            count++;
        }
    }

    return count > 0 ? totalAge / count : 0.0;
}

// Function to calculate survival rate by gender
void calculateSurvivalRate() {
    int maleSurvived = 0, maleTotal = 0;
    int femaleSurvived = 0, femaleTotal = 0;

    for (int i = 0; i < passengerCount; i++) {
        if (strcmp(passengers[i].sex, "male") == 0) {
            maleTotal++;
            if (passengers[i].survived) maleSurvived++;
        } else if (strcmp(passengers[i].sex, "female") == 0) {
            femaleTotal++;
            if (passengers[i].survived) femaleSurvived++;
        }
    }

    printf("Male Survival Rate: %.2f%%\n", maleTotal > 0 ? (maleSurvived * 100.0 / maleTotal) : 0.0);
    printf("Female Survival Rate: %.2f%%\n", femaleTotal > 0 ? (femaleSurvived * 100.0 / femaleTotal) : 0.0);
}

// Function to display survivors
void displaySurvivors() {
    printf("Survivors:\n");
    printf("Name, Age, Class\n");
    for (int i = 0; i < passengerCount; i++) {
        if (passengers[i].survived) {
            printf("%s, %.1f, %d\n", passengers[i].name, passengers[i].age, passengers[i].pclass);
        }
    }
}

// Function to display passengers with missing cabin details
void displayMissingCabinDetails() {
    printf("Passengers with Missing Cabin Details:\n");
    for (int i = 0; i < passengerCount; i++) {
        if (strlen(passengers[i].cabin) == 0 || strcmp(passengers[i].cabin, " ") == 0) {
            printf("%s, Age: %.1f, Class: %d\n", passengers[i].name, passengers[i].age, passengers[i].pclass);
        }
    }
}

int main() {
    loadDataset("Titanic.csv");

    printf("Average Age of Passengers: %.2f\n", calculateAverageAge());
    calculateSurvivalRate();
    displaySurvivors();
    displayMissingCabinDetails();

    return 0;
}
