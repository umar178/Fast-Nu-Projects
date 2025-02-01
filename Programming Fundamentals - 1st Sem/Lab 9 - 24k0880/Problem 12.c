#include <stdio.h>

void findMaxMin(int *arr, int size, int *max, int *min) {
    *max = *min = *arr;
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        if (*ptr > *max)
            *max = *ptr;
        if (*ptr < *min)
            *min = *ptr;
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, size, &max, &min);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
