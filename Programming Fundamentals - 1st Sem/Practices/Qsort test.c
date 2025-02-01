#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *arr[] = {"Banana", "Apple", "Cherry", "Mango", "Peach"};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(char *), compareStrings);

    printf("Sorted array of strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
