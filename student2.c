#include <stdio.h>
#include "student2.h"

const char *subject_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};

void inputStudentData(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter marks:\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("%s - Internals: ", subject_names[i]);
        scanf("%f", &student->exam_marks[i]);
        printf("%s - ESA: ", subject_names[i]);
        scanf("%f", &student->exam_marks[i + MAX_SUBJECTS]);
    }
}

float calculateAverage(float marks[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}

char gradeAssignment(float avg) {
    char grade;
    if (avg >= 90) {
        grade = 'S';
    } else if (avg >= 80) {
        grade = 'A';
    } else if (avg >= 70) {
        grade = 'B';
    } else if (avg >= 60) {
        grade = 'C';
    } else if (avg >= 50) {
        grade = 'D';
    } else if (avg >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }
    return grade;
}

void generateGradeCard(struct Student *student) {
    printf("\n===== Final Grade Card for %s =====\n", student->name);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        float avg = (student->exam_marks[i] + student->exam_marks[i + MAX_SUBJECTS]) / 2;
        char grade = gradeAssignment(avg);
        printf("%s Final Grade: %c\n", subject_names[i], grade);
    }
}
