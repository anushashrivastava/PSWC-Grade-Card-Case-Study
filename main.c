#include <stdio.h>
#include "student.h"

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        char name[50];
        float exam_marks[10]; 

        printf("\nStudent %d:\n\n", i + 1);
        inputStudentData(name, exam_marks);

        generateGradeCard(name, exam_marks);
    }

    return 0;
}


