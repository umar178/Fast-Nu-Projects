#include <stdio.h>

void findIntersection(int *arr1, int *arr2, int size1, int size2) {
    for (int *p1 = arr1; p1 < arr1 + size1; p1++) {
        for (int *p2 = arr2; p2 < arr2 + size2; p2++) {
            if (*p1 == *p2) {
                printf("%d ", *p1);
            }
        }
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int size1 = 5, size2 = 5;

    printf("Intersection: ");
    findIntersection(arr1, arr2, size1, size2);
    printf("\n");

    return 0;
}
