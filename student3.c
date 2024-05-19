#include <stdio.h>
#include "student3.h"

const char *subject_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};
const int subject_credits[] = {5, 5, 4, 4, 3};

void inputStudentData(char name[], float exam_marks[]) {
    printf("Enter student name: ");
    scanf("%49s", name);
    printf("Enter marks:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - Internals: ", subject_names[i]);
        scanf("%f", &exam_marks[i]);
        printf("%s - ESA: ", subject_names[i]);
        scanf("%f", &exam_marks[i+5]);
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

int gradePoint(char grade) {
    switch (grade) {
        case 'S': return 10;
        case 'A': return 9;
        case 'B': return 8;
        case 'C': return 7;
        case 'D': return 6;
        case 'E': return 5;
        case 'F': return 0;
        default: return 0;
    }
}

float calculateSGPA(char grades[]) {
    int total_credits = 0;
    int weighted_grade_points = 0;
    for (int i = 0; i < 5; i++) {
        int grade_point = gradePoint(grades[i]);
        weighted_grade_points += grade_point * subject_credits[i];
        total_credits += subject_credits[i];
    }
    return (float)weighted_grade_points / total_credits;
}

void generateGradeCard(char name[], float exam_marks[]) {
    printf("\n===== Final Grade Card for %s =====\n", name);
    char grades[5];
    for (int i = 0; i < 5; i++) {
        printf("%s - Internals: %.2f\n", subject_names[i], exam_marks[i]);
        printf("%s - ESA: %.2f\n", subject_names[i], exam_marks[i+5]);
        float avg = (exam_marks[i] + exam_marks[i+5]) / 2;
        char grade = gradeAssignment(avg);
        grades[i] = grade;
        printf("%s Final Grade: %c\n", subject_names[i], grade);
        printf("\n");
    }
    float sgpa = calculateSGPA(grades);
    printf("SGPA: %.2f\n", sgpa);
}


