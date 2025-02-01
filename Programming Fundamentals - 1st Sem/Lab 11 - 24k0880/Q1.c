#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int employeeID;
    float salary;
};

struct Department {
    char departmentName[50];
    struct Employee employees[10];
    int employeeCount;
};

float calculateTotalSalary(struct Department dept) {
    float totalSalary = 0.0;
    for (int i = 0; i < dept.employeeCount; i++) {
        totalSalary += dept.employees[i].salary;
    }
    return totalSalary;
}

int main() {
    struct Department dept;

    printf("Enter department name: ");
    scanf("%s", dept.departmentName);

    printf("Enter the number of employees in the department: ");
    scanf("%d", &dept.employeeCount);

    for (int i = 0; i < dept.employeeCount; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", dept.employees[i].name);
        printf("Employee ID: ");
        scanf("%d", &dept.employees[i].employeeID);
        printf("Salary: ");
        scanf("%f", &dept.employees[i].salary);
    }

    float totalSalary = calculateTotalSalary(dept);
    printf("Total salary of employees in the %s department: %.2f\n", dept.departmentName, totalSalary);

    return 0;
}
