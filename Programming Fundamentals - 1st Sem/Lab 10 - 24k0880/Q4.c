#include <stdio.h>
#include <string.h>

#define MAX_CARS 10

typedef struct {
    char make[20];
    char model[20];
    int year;
    float price;
    float mileage;
} Car;

void addCar(Car cars[], int *count);
void displayCars(Car cars[], int count);
void searchCarByModel(Car cars[], int count);

int main() {
    Car cars[MAX_CARS];
    int carCount = 0;

    int choice;
    do {
        printf("\nCar Dealership System\n");
        printf("1. Add New Car\n");
        printf("2. Display All Cars\n");
        printf("3. Search Car by Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCarByModel(cars, carCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addCar(Car cars[], int *count) {
    if (*count >= MAX_CARS) {
        printf("Car inventory is full!\n");
        return;
    }

    printf("Enter car make: ");
    scanf("%s", cars[*count].make);
    printf("Enter car model: ");
    scanf("%s", cars[*count].model);
    printf("Enter year: ");
    scanf("%d", &cars[*count].year);
    printf("Enter price: ");
    scanf("%f", &cars[*count].price);
    printf("Enter mileage: ");
    scanf("%f", &cars[*count].mileage);

    (*count)++;
    printf("Car added successfully!\n");
}

void displayCars(Car cars[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Make: %s, Model: %s, Year: %d, Price: %.2f, Mileage: %.1f\n",
               cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}

void searchCarByModel(Car cars[], int count) {
    char model[20];
    printf("Enter model to search: ");
    scanf("%s", model);

    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].model, model) == 0) {
            printf("Found: Make: %s, Model: %s, Year: %d, Price: %.2f, Mileage: %.1f\n",
                   cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
        }
    }
}
