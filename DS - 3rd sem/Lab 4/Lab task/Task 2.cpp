#include <iostream>
#include <string>
using namespace std;

void displayArray(string arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSortStrings(string arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            string temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void selectionSortCount(int arr[], int size) {
    int swapCount = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount++;
        }
    }
    cout << "Sorted array: ";
    displayArray(arr, size);
    cout << "Number of swaps: " << swapCount << endl;
}

int main() {
    int choice;
    cout << "Task # 02 Menu\n";
    cout << "1. Sort 5 cities alphabetically\n";
    cout << "2. Count swaps in Selection Sort on {29, 10, 14, 37, 13}\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        const int SIZE = 5;
        string cities[SIZE];
        cout << "Enter 5 city names: ";
        for (int i = 0; i < SIZE; i++)
            cin >> cities[i];

        cout << "\nCities before sorting: ";
        displayArray(cities, SIZE);

        selectionSortStrings(cities, SIZE);

        cout << "Cities after sorting: ";
        displayArray(cities, SIZE);
    } 
    else if (choice == 2) {
        int arr[] = {29, 10, 14, 37, 13};
        int size = 5;

        cout << "Original array: ";
        displayArray(arr, size);

        selectionSortCount(arr, size);
    } 
    else {
        cout << "Invalid choice!";
    }

    return 0;
}

