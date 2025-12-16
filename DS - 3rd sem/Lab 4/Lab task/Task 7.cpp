#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key, int &comparisons) {
    int left = 0, right = size - 1;
    comparisons = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        comparisons++;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int key, int &comparisons) {
    int low = 0, high = size - 1;
    comparisons = 0;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        comparisons++;
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int choice;
    cout << "Task # 07 Menu\n";
    cout << "1. Interpolation Search for product prices\n";
    cout << "2. Compare Binary vs Interpolation Search for 45\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
        int size = 8, key, comparisons;

        cout << "Enter price to search: ";
        cin >> key;

        int result = interpolationSearch(arr, size, key, comparisons);

        if (result != -1)
            cout << "Price found at position " << result << endl;
        else
            cout << "Price not available" << endl;

        cout << "Comparisons made: " << comparisons << endl;
    }
    else if (choice == 2) {
        int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
        int size = 10, key = 45;
        int compBin, compInterp;

        int resBin = binarySearch(arr, size, key, compBin);
        int resInterp = interpolationSearch(arr, size, key, compInterp);

        cout << "Searching for " << key << "...\n";

        if (resBin != -1)
            cout << "Binary Search: Found at index " << resBin << ", Comparisons = " << compBin << endl;
        else
            cout << "Binary Search: Not found, Comparisons = " << compBin << endl;

        if (resInterp != -1)
            cout << "Interpolation Search: Found at index " << resInterp << ", Comparisons = " << compInterp << endl;
        else
            cout << "Interpolation Search: Not found, Comparisons = " << compInterp << endl;

        if (compInterp < compBin)
            cout << "Conclusion: Interpolation Search is more efficient in this case." << endl;
        else if (compInterp > compBin)
            cout << "Conclusion: Binary Search is more efficient in this case." << endl;
        else
            cout << "Conclusion: Both performed equally." << endl;
    }
    else {
        cout << "Invalid choice!";
    }

    return 0;
}

