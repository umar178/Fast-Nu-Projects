#include<stdio.h>

int main() {
    int arr[] = {2, 3, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Numbers occurring more than once: ");
    for (i = 0; i < n; i++) {
        int index = arr[i] % n;
        if (arr[index] >= n) {
            printf("%d ", index);
        }
        arr[index] += n;
    }
    printf("\n");
    return 0;
}