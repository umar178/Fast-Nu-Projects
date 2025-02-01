#include<stdio.h>

typedef struct crop crop;
typedef struct weather weather;
typedef struct equipment equipment;
typedef struct sensor sensor;
typedef struct regionalHub regionalHub;
typedef struct centralHub centralHub;

typedef struct field{
	int coords;
	int health;
	int moisture;
	crop *c;   
    int cropCount;
    equipment *e;
    int equipmentCount;
    sensor *s; 
    int sensorCount; 
}field;

typedef struct crop{
	char croptype[50];
	char growthStage[50];
	int yield;
	weather *w;
}crop;

typedef struct weather{
	int temp;
	int rainfall;
	char wind[50];
}weather;

typedef struct equipment{
	char operationalStatus[50];
	int fuel;
	char activity[50];
}equipment;

typedef struct sensor{
	char nutrients[50];
	int PH_level;
	char pest_activity[50];
}sensor;

typedef struct regionalHub{
	field *fields;
	int aggregate;
	char resourceDistribution[500];
	char emergencyResponse[500];
}regionalHub;

typedef struct centralHub{
	regionalHub *RH;
	char AI_Data[1000];
}centralHub;

void addField(field *f) {
    printf("Enter GPS coordinates (integer): ");
    scanf("%d", &f->coords);

    printf("Enter soil health (0-100): ");
    scanf("%d", &f->health);

    printf("Enter moisture level (0-100): ");
    scanf("%d", &f->moisture);

    printf("Enter number of crops: ");
    scanf("%d", &f->cropCount);
    f->c = (crop *)malloc(f->cropCount * sizeof(crop));

    for (int i = 0; i < f->cropCount; i++) {
        printf("\nCrop %d\n", i + 1);
        printf("Enter crop type: ");
        scanf("%s", f->c[i].croptype);
        printf("Enter growth stage: ");
        scanf("%s", f->c[i].growthStage);
        printf("Enter expected yield: ");
        scanf("%d", &f->c[i].yield);

        f->c[i].w = (weather *)malloc(sizeof(weather));
        printf("Enter temperature: ");
        scanf("%d", &f->c[i].w->temp);
        printf("Enter rainfall (mm): ");
        scanf("%d", &f->c[i].w->rainfall);
        printf("Enter wind description: ");
        scanf("%s", f->c[i].w->wind);
    }

    printf("\nEnter number of equipment: ");
    scanf("%d", &f->equipmentCount);
    f->e = (equipment *)malloc(f->equipmentCount * sizeof(equipment));

    for (int i = 0; i < f->equipmentCount; i++) {
        printf("\nEquipment %d\n", i + 1);
        printf("Enter operational status: ");
        scanf("%s", f->e[i].operationalStatus);
        printf("Enter fuel level: ");
        scanf("%d", &f->e[i].fuel);
        printf("Enter activity description: ");
        scanf("%s", f->e[i].activity);
    }

    printf("\nEnter number of sensors: ");
    scanf("%d", &f->sensorCount);
    f->s = (sensor *)malloc(f->sensorCount * sizeof(sensor));

    for (int i = 0; i < f->sensorCount; i++) {
        printf("\nSensor %d\n", i + 1);
        printf("Enter nutrient data: ");
        scanf("%s", f->s[i].nutrients);
        printf("Enter PH level: ");
        scanf("%d", &f->s[i].PH_level);
        printf("Enter pest activity description: ");
        scanf("%s", f->s[i].pest_activity);
    }
}

void displayField(field *f) {
    printf("\nField Details:\n");
    printf("GPS Coordinates: %d\n", f->coords);
    printf("Soil Health: %d\n", f->health);
    printf("Moisture Level: %d\n", f->moisture);

    printf("\nCrops:\n");
    for (int i = 0; i < f->cropCount; i++) {
        printf("Crop %d: %s, Growth Stage: %s, Yield: %d\n",
               i + 1, f->c[i].croptype, f->c[i].growthStage, f->c[i].yield);
        printf("Weather: Temp: %d, Rainfall: %d, Wind: %s\n",
               f->c[i].w->temp, f->c[i].w->rainfall, f->c[i].w->wind);
    }

    printf("\nEquipment:\n");
    for (int i = 0; i < f->equipmentCount; i++) {
        printf("Equipment %d: Status: %s, Fuel: %d, Activity: %s\n",
               i + 1, f->e[i].operationalStatus, f->e[i].fuel, f->e[i].activity);
    }

    printf("\nSensors:\n");
    for (int i = 0; i < f->sensorCount; i++) {
        printf("Sensor %d: Nutrients: %s, PH Level: %d, Pest Activity: %s\n",
               i + 1, f->s[i].nutrients, f->s[i].PH_level, f->s[i].pest_activity);
    }
}

int main() {
    int fieldCount;
    printf("Enter the number of fields: ");
    scanf("%d", &fieldCount);

    field *fields = (field *)malloc(fieldCount * sizeof(field));

    for (int i = 0; i < fieldCount; i++) {
        printf("\n--- Adding Field %d ---\n", i + 1);
        addField(&fields[i]);
    }

    for (int i = 0; i < fieldCount; i++) {
        printf("\n--- Field %d Details ---\n", i + 1);
        displayField(&fields[i]);
    }

    for (int i = 0; i < fieldCount; i++) {
        for (int j = 0; j < fields[i].cropCount; j++) {
            free(fields[i].c[j].w);
        }
        free(fields[i].c);
        free(fields[i].e);
        free(fields[i].s);
    }
    free(fields);

    return 0;
}