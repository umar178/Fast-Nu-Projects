#include<stdio.h>

typedef struct student{
	int id;
	char name[50];
	float marks;
}student;

void Print(student n){
	printf("ID: %d\nName: %s\nMark: %f", n.id, n.name, n.marks);
}

main(){
	student No1 = {80, "Umar", 75.6};
	
	Print(No1);
}