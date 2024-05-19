#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student3.h"

#define MAX_STUDENTS 100

void loadStudents(Student students[], int *num_students) {
    FILE *file = fopen("marks.csv", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file); 

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%49[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
               students[*num_students].name,
               &students[*num_students].exam_marks[0], &students[*num_students].exam_marks[1],
               &students[*num_students].exam_marks[2], &students[*num_students].exam_marks[3],
               &students[*num_students].exam_marks[4], &students[*num_students].exam_marks[5],
               &students[*num_students].exam_marks[6], &students[*num_students].exam_marks[7],
               &students[*num_students].exam_marks[8], &students[*num_students].exam_marks[9]);
        (*num_students)++;
        if (*num_students >= MAX_STUDENTS) break;
    }

    fclose(file);
}

void saveStudents(Student students[], int num_students) {
    FILE *file = fopen("marks.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Name,Physics - Internals,Physics - ESA,PSWC - Internals,PSWC - ESA,Mathematics - Internals,Mathematics - ESA,Electrical - Internals,Electrical - ESA,Mechanical - Internals,Mechanical - ESA\n");
    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
                students[i].name,
                students[i].exam_marks[0], students[i].exam_marks[1],
                students[i].exam_marks[2], students[i].exam_marks[3],
                students[i].exam_marks[4], students[i].exam_marks[5],
                students[i].exam_marks[6], students[i].exam_marks[7],
                students[i].exam_marks[8], students[i].exam_marks[9]);
    }

    fclose(file);
}

void addStudent(Student students[], int *num_students) {
    if (*num_students >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    printf("Enter details for new student:\n");
    inputStudentData(students[*num_students].name, students[*num_students].exam_marks);
    (*num_students)++;
    saveStudents(students, *num_students);
}

void deleteStudent(Student students[], int *num_students) {
    char name[50];
    printf("Enter the name of the student to delete: ");
    scanf("%49s", name);

    int found = 0;
    for (int i = 0; i < *num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            (*num_students)--;
            break;
        }
    }

    if (found) {
        printf("Student %s deleted successfully.\n", name);
        saveStudents(students, *num_students);
    } else {
        printf("Student %s not found.\n", name);
    }
}

void searchStudent(Student students[], int num_students) {
    char name[50];
    printf("Enter the name of the student to search: ");
    scanf("%49s", name);

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            generateGradeCard(students[i].name, students[i].exam_marks);
            return;
        }
    }

    printf("Student %s not found.\n", name);
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;

    loadStudents(students, &num_students);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Grade Cards\n");
        printf("4. Search Student\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                deleteStudent(students, &num_students);
                break;
            case 3:
                for (int i = 0; i < num_students; i++) {
                    generateGradeCard(students[i].name, students[i].exam_marks);
                }
                break;
            case 4:
                searchStudent(students, num_students);
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


