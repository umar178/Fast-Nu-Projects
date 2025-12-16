#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSortAscending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int choice;
    cout << "Task # 03 Menu\n";
    cout << "1. Sort students' marks in ascending order\n";
    cout << "2. Sort numbers {15, 2, 78, 25, 63} in descending order\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Enter number of students: ";
        cin >> n;
        int marks[n];
        cout << "Enter " << n << " marks: ";
        for (int i = 0; i < n; i++)
            cin >> marks[i];

        cout << "\nMarks before sorting: ";
        displayArray(marks, n);

        insertionSortAscending(marks, n);

        cout << "Marks after sorting (Ascending): ";
        displayArray(marks, n);
    } 
    else if (choice == 2) {
        int arr[] = {15, 2, 78, 25, 63};
        int size = 5;

        cout << "Original array: ";
        displayArray(arr, size);

        insertionSortDescending(arr, size);

        cout << "Array after sorting (Descending): ";
        displayArray(arr, size);
    } 
    else {
        cout << "Invalid choice!";
    }

    return 0;
}

