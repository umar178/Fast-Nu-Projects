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

int main() {
    int arr[] = {101, 105, 110, 120, 135, 150};
    int size = 6;

    int roll, comparisons;
    cout << "Enter roll number to search: ";
    cin >> roll;

    int result = binarySearch(arr, size, roll, comparisons);

    if (result != -1)
        cout << "Roll number found at index " << result << endl;
    else
        cout << "Roll number not found" << endl;

    cout << "Number of comparisons made: " << comparisons << endl;

    return 0;
}

