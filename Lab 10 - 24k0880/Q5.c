#include <stdio.h>

void bubbleSortRecursive(int arr[], int size);

int main() {
    int arr[] = {5, 3, 8, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSortRecursive(int arr[], int size) {
    if (size <= 1) return;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSortRecursive(arr, size - 1);
}
