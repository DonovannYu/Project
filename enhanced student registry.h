#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#include <stdio.h>

#define MAX_STUDENTS 100
#define DATA_FILE "students.dat"

typedef struct {
    int id;
    char name[100];
    char major[50];
    float gpa;
    int credits;
} Student;

/* Global data */
extern Student students[MAX_STUDENTS];
extern int studentCount;

/* Core Functions */
void addStudent(void);
void displayAllStudents(void);
void searchByID(void);
void findByGPA(void);
void findByMajor(void);

/* File Handling */
void saveStudentsToFile(void);
void loadStudentsFromFile(void);

#endif
