#include <stdio.h>

#define MAX_TEMP 35 

void checkTemperature(float temperatures[], int size);

int main() {
    float temperatures[] = {30, 36, 32, 38, 28, 40};
    int size = sizeof(temperatures) / sizeof(temperatures[0]);

    checkTemperature(temperatures, size);

    return 0;
}

void checkTemperature(float temperatures[], int size) {
    int exceedCount = 0;

    for (int i = 0; i < size; i++) {
        if (temperatures[i] > MAX_TEMP) {
            printf("Temperature %.1f exceeds the limit.\n", temperatures[i]);
            exceedCount++;
        }
    }

    printf("Total exceedances: %d\n", exceedCount);
}
