#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

typedef struct
{
    int id;
    char name[100];
    char major[50];
    float gpa;
    int credits;
} Student;

/* Core Functions */
void addStudent(Student students[], int *count);
void displayAllStudents(Student students[], int count);
void searchByID(Student students[], int count);
void findByGPA(Student students[], int count);
void findByMajor(Student students[], int count);

/* File Functions */
void saveStudentsToFile(Student students[], int count);
void loadStudentsFromFile(Student students[], int *count);

#endif
