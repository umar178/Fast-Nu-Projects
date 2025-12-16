#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int size) {
    cout << "Gap sequence: ";
    for (int gap = size / 2; gap > 0; gap /= 2) {
        cout << gap << " ";
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    cout << endl;
}

int insertionSortCount(int arr[], int size) {
    int shifts = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
    }
    return shifts;
}

int shellSortCount(int arr[], int size) {
    int shifts = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                shifts++;
            }
            arr[j] = temp;
        }
    }
    return shifts;
}

int main() {
    int choice;
    cout << "Task # 04 Menu\n";
    cout << "1. Shell Sort on 20 random numbers\n";
    cout << "2. Compare Shell Sort vs Insertion Sort on {50, 40, 30, 20, 10}\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        const int SIZE = 20;
        int arr[SIZE];
        srand(time(0));
        for (int i = 0; i < SIZE; i++)
            arr[i] = rand() % 100;

        cout << "Original array: ";
        displayArray(arr, SIZE);

        shellSort(arr, SIZE);

        cout << "Sorted array: ";
        displayArray(arr, SIZE);
    }
    else if (choice == 2) {
        int arr1[] = {50, 40, 30, 20, 10};
        int arr2[] = {50, 40, 30, 20, 10};
        int size = 5;

        cout << "Original array: ";
        displayArray(arr1, size);

        int shiftsInsertion = insertionSortCount(arr1, size);
        int shiftsShell = shellSortCount(arr2, size);

        cout << "Sorted with Insertion Sort: ";
        displayArray(arr1, size);
        cout << "Shifts (Insertion Sort): " << shiftsInsertion << endl;

        cout << "Sorted with Shell Sort: ";
        displayArray(arr2, size);
        cout << "Shifts (Shell Sort): " << shiftsShell << endl;

        if (shiftsShell < shiftsInsertion)
            cout << "Shell Sort is faster in this case." << endl;
        else if (shiftsShell > shiftsInsertion)
            cout << "Insertion Sort is faster in this case." << endl;
        else
            cout << "Both performed equally." << endl;
    }
    else {
        cout << "Invalid choice!";
    }

    return 0;
}

