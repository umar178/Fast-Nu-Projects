#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "Early stopping: Array sorted after pass " << i + 1 << endl;
            break;
        }
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    cout << "Enter 10 integers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];

    cout << "\nArray before sorting: ";
    displayArray(arr, SIZE);

    bubbleSort(arr, SIZE);

    cout << "Array after sorting: ";
    displayArray(arr, SIZE);

    return 0;
}

