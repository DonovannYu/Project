#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#define MAX 10

typedef struct
{
    int id;
    char name[100];
    char major[50];
    float gpa;
    int credits;
} Student;

void addStudent(Student students[], int *count);
void displayAllStudents(Student students[], int count);
void searchByID(Student students[], int count);
void findByGPA(Student students[], int count);
void findByMajor(Student students[], int count);

void saveStudentsToFile(Student students[], int count);
void loadStudentsFromFile(Student students[], int *count);

#endif
