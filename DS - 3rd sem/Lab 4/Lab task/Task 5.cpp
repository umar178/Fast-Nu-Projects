#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int getNextGap(int gap) {
    gap = (gap * 10) / 13;  // shrink factor = 1.3
    if (gap < 1) return 1;
    return gap;
}

void combSort(int arr[], int size) {
    int gap = size;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        cout << "Gap used: " << gap << endl;
        swapped = false;
        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

int combSortCount(int arr[], int size) {
    int gap = size;
    bool swapped = true;
    int swaps = 0;
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
    return swaps;
}

int bubbleSortCount(int arr[], int size) {
    int swaps = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int choice;
    cout << "Task # 05 Menu\n";
    cout << "1. Comb Sort with gap sequence (user input)\n";
    cout << "2. Compare Comb Sort vs Bubble Sort on {9,8,7,6,5,4,3,2,1}\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;
        int arr[n];
        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << "Original array: ";
        displayArray(arr, n);

        combSort(arr, n);

        cout << "Sorted array: ";
        displayArray(arr, n);
    }
    else if (choice == 2) {
        int arr1[] = {9,8,7,6,5,4,3,2,1};
        int arr2[] = {9,8,7,6,5,4,3,2,1};
        int size = 9;

        cout << "Original array: ";
        displayArray(arr1, size);

        int swapsComb = combSortCount(arr1, size);
        int swapsBubble = bubbleSortCount(arr2, size);

        cout << "Sorted with Comb Sort: ";
        displayArray(arr1, size);
        cout << "Swaps (Comb Sort): " << swapsComb << endl;

        cout << "Sorted with Bubble Sort: ";
        displayArray(arr2, size);
        cout << "Swaps (Bubble Sort): " << swapsBubble << endl;

        if (swapsComb < swapsBubble)
            cout << "Comb Sort is faster because it reduces gap size, moving elements long distances early." << endl;
        else
            cout << "Bubble Sort is faster (unlikely for large arrays)." << endl;
    }
    else {
        cout << "Invalid choice!";
    }

    return 0;
}

