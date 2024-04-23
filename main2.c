#include <stdio.h>
#include "student2.h"

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct Student students[num_students];

    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n\n", i + 1);
        inputStudentData(&students[i]);
    }

    for (int i = 0; i < num_students; i++) {
        generateGradeCard(&students[i]);
    }

    return 0;
}
