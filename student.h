#ifndef STUDENT_H
#define STUDENT_H

void inputStudentData(char name[], float exam_marks[]);
float calculateAverage(float marks[], int size);
char gradeAssignment(float avg);
void generateGradeCard(char name[], float exam_marks[]);

#endif

