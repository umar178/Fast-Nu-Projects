#include <iostream>
using namespace std;

void findPeaks(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == n - 1 || arr[i] > arr[i + 1])) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int arr[] = {1, 3, 2, 5, 3, 7, 6};
    int n = 7;

    findPeaks(arr, n);

    return 0;
}
