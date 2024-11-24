#include<stdio.h>

typedef struct student{
	int id;
	char name[50];
	float marks;
}student;

void TakeInput(student s[], int n){
	for(int i = 0; i < n; i++){
		printf("Details for student %d:\n", i);
		scanf("%d", &s[i].id);
		scanf("%s", &s[i].name);
		scanf("%f", &s[i].marks);
	}
}

void Print(student s[], int n){
	printf("\nStudents Info:\n\n");
	for(int i = 0; i < n; i++){
		printf("Student %d;\n", i+1);
		printf("ID: %d\nName: %s\nMark: %f\n", s[i].id, s[i].name, s[i].marks);
		printf("\n");
	}
}

main(){
	student No1[2];
	
	TakeInput(No1, 2);
	
	Print(No1, 2);
}