#ifndef STUDENT2_H
#define STUDENT2_H

#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    float exam_marks[MAX_SUBJECTS * 2]; 
};

void inputStudentData(struct Student *student);
float calculateAverage(float marks[], int size);
char gradeAssignment(float avg);
void generateGradeCard(struct Student *student);

#endif
