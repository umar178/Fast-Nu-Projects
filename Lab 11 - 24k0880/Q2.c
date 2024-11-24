#include<stdio.h>

typedef struct details{
	char name[50];
	int id;
	int salary;
}details;

void addEmployee(){
	details *employee;
	int n;
	
	FILE *f = fopen("Data.bin", "wb");
	
	printf("Enter number of records: ");
	scanf("%d", &n);
	
	employee = (details*)malloc(sizeof(details) * n);
	
	for(int i = 0; i < n; i++){
		printf("Data for employee %d:\n", i+1);
		printf("Name: ");
		scanf("%s", (employee + i)->name);
		printf("id: ");
		scanf("%d", &(employee + i)->id);
		printf("salary: ");
		scanf("%d", &(employee + i)->salary);
	}
	
	size_t written = fwrite(employee, sizeof(details) * n, 1, f);
	
	if(written != 1){
		printf("error writting file");
	}
	else{
		printf("success writting file\n\n");
	}
	
	fclose(f);
}

void readData() {
	int t_salary;
    FILE *f = fopen("Data.bin", "rb");
    if (f == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    int fileSize = ftell(f);
    rewind(f);

    int count = fileSize / sizeof(struct details);

    struct details *data = (struct details *)malloc(count * sizeof(struct details));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(f);
        return;
    }

    fread(data, sizeof(struct details), count, f);
    fclose(f);

    printf("Number of records: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", data[i].id, data[i].name, data[i].salary);
        t_salary += data[i].salary;
    }
    
    printf("total salary is %d", t_salary);

    free(data);
}

main(){
	while(1){
		int choice;
		
		printf("Select an Option:\n");
		printf("1: Create Record\n");
		printf("2: Read Record\n");
		printf("3: Exit\n");
		
		printf("Input: ");
		scanf("%d", &choice);
		
		if(choice == 1){
			addEmployee();
		}
		else if(choice == 2){
			readData();
		}
		else{
			break;
		}
	}
	
}