#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_STUDENTS 50

struct Course {
    char name[50];
    char code[10];
    char instructor[50];
};

struct Student {
    char name[50];
    int rollNumber;
    struct Course courses[MAX_COURSES];
    int courseCount;
};

void saveData(struct Student students[], int studentCount) {
    FILE *f = fopen("EnrollmentData.bin", "wb");
    if (f == NULL) return;
    fwrite(students, sizeof(struct Student), studentCount, f);
    fclose(f);
}

void loadData(struct Student students[], int *studentCount) {
    FILE *f = fopen("EnrollmentData.bin", "rb");
    if (f == NULL) return;
    *studentCount = fread(students, sizeof(struct Student), MAX_STUDENTS, f);
    fclose(f);
}

void displayCourses(struct Student students[], int studentCount, int rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Name: %s\n", students[i].name);
            printf("Courses Enrolled:\n");
            for (int j = 0; j < students[i].courseCount; j++) {
                printf("Course Name: %s, Code: %s, Instructor: %s\n",
                       students[i].courses[j].name,
                       students[i].courses[j].code,
                       students[i].courses[j].instructor);
            }
            return;
        }
    }
    printf("Student not found.\n");
}

void addStudent(struct Student students[], int *studentCount) {
    struct Student newStudent;
    printf("Enter student name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Enter the number of courses to enroll: ");
    scanf("%d", &newStudent.courseCount);

    for (int i = 0; i < newStudent.courseCount; i++) {
        printf("Enter course name: ");
        scanf(" %[^\n]", newStudent.courses[i].name);
        printf("Enter course code: ");
        scanf(" %[^\n]", newStudent.courses[i].code);
        printf("Enter instructor name: ");
        scanf(" %[^\n]", newStudent.courses[i].instructor);
    }

    students[*studentCount] = newStudent;
    (*studentCount)++;
    saveData(students, *studentCount);
}

void generateReport(struct Student students[], int studentCount) {
    struct Course courseList[MAX_COURSES * MAX_STUDENTS];
    int courseCounts[MAX_COURSES * MAX_STUDENTS] = {0};
    int courseTotal = 0;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < students[i].courseCount; j++) {
            int found = 0;
            for (int k = 0; k < courseTotal; k++) {
                if (strcmp(courseList[k].name, students[i].courses[j].name) == 0 &&
                    strcmp(courseList[k].code, students[i].courses[j].code) == 0) {
                    courseCounts[k]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                courseList[courseTotal] = students[i].courses[j];
                courseCounts[courseTotal]++;
                courseTotal++;
            }
        }
    }

    printf("Course Enrollment Report:\n");
    for (int i = 0; i < courseTotal; i++) {
        printf("Course Name: %s, Code: %s, Enrolled Students: %d\n",
               courseList[i].name, courseList[i].code, courseCounts[i]);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    loadData(students, &studentCount);

    int choice, rollNumber;
    while (1) {
        printf("1. Add Student\n2. Display Courses by Roll Number\n3. Generate Report\n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            addStudent(students, &studentCount);
        } else if (choice == 2) {
            printf("Enter roll number: ");
            scanf("%d", &rollNumber);
            displayCourses(students, studentCount, rollNumber);
        } else if (choice == 3) {
            generateReport(students, studentCount);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
