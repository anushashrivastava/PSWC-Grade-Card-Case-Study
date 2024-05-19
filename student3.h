#ifndef STUDENT3_H
#define STUDENT3_H

typedef struct {
    char name[50];
    float exam_marks[10];
} Student;

void inputStudentData(char name[], float exam_marks[]);
float calculateAverage(float marks[], int size);
char gradeAssignment(float avg);
int gradePoint(char grade);
float calculateSGPA(char grades[]);
void generateGradeCard(char name[], float exam_marks[]);

#endif


