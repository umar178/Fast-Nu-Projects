#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    double rating;
    int runtime;
    char encodingFormats[50];
} ContentMetadata;

double** engagementMatrix;

typedef struct {
    int resolution;
    double bandwidth;
    char playbackHistory[50];
} DevicePreferences;

DevicePreferences*** deviceMatrix;

ContentMetadata*** contentMatrix;

int main() {
    int numUsers, numCategories, numDevices;

    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    printf("Enter the number of content categories: ");
    scanf("%d", &numCategories);

    printf("Enter the number of devices per user: ");
    scanf("%d", &numDevices);

    engagementMatrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        engagementMatrix[i] = (double*)calloc(numCategories, sizeof(double));
    }

    deviceMatrix = (DevicePreferences***)malloc(numUsers * sizeof(DevicePreferences**));
    for (int i = 0; i < numUsers; i++) {
        deviceMatrix[i] = (DevicePreferences**)malloc(numDevices * sizeof(DevicePreferences*));
        for (int j = 0; j < numDevices; j++) {
            deviceMatrix[i][j] = (DevicePreferences*)malloc(sizeof(DevicePreferences));
        }
    }

    for (int i = 0; i < numUsers; i++) {
        printf("\nEnter engagement scores for User %d:\n", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("Category %d score: ", j + 1);
            scanf("%lf", &engagementMatrix[i][j]);
        }
    }

    for (int i = 0; i < numUsers; i++) {
        printf("\nEnter device preferences for User %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("Device %d resolution: ", j + 1);
            scanf("%d", &deviceMatrix[i][j]->resolution);

            printf("Device %d bandwidth usage (GB): ", j + 1);
            scanf("%lf", &deviceMatrix[i][j]->bandwidth);

            printf("Device %d playback history: ", j + 1);
            scanf(" %[^\n]", deviceMatrix[i][j]->playbackHistory);
        }
    }

    printf("\nUser Engagement Scores:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.1f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDevice Preferences:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("\nUser %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("Device %d - Resolution: %d, Bandwidth: %.1f GB, Playback: %s\n",
                   j + 1, deviceMatrix[i][j]->resolution, deviceMatrix[i][j]->bandwidth,
                   deviceMatrix[i][j]->playbackHistory);
        }
    }

    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
        for (int j = 0; j < numDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);

    return 0;
}
