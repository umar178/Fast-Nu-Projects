#include<stdio.h>

typedef struct employee{
	int id;
	char name[50];
	int date;
}employee;

void Tenure(employee e[], int count){
	int c_date;
    printf("Enter current date (DDMMYYYY): ");
    scanf("%d", &c_date);

    int c_y = c_date % 10000;
    int c_m = (c_date / 10000) % 100;
    int c_d = c_date / 1000000;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < count; i++) {
        int y = e[i].date % 10000;
        int m = (e[i].date / 10000) % 100;
        int d = e[i].date / 1000000;

        int tenure = 0;

        tenure += (c_y - y) * 365;

        if (c_m > m || c_y > y) {
            for (int j = m - 1; j < c_m - 1; j++) {
                tenure += days_in_month[j];
            }
        }

        tenure += c_d - d;

        printf("Tenure for Employee %d (%s) in days: %d\n", e[i].id, e[i].name, tenure);
    }
}

main(){
	employee e[4];
	
	for(int i = 0; i < sizeof(e)/sizeof(employee); i++){
		printf("Enter data for employee %d\n", i + 1);
		printf("Id: ");
		scanf("%d", &e[i].id);
		printf("Name: ");
		scanf("%s", e[i].name);
		printf("Date of joining (Format: DDMMYYYY): ");
		scanf("%d", &e[i].date);
		//printf("year = %d", (e[i].date / 10000) % 100);
	}
	
	Tenure(e, 4);
}