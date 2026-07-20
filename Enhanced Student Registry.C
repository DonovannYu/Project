#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_registry.h"

Student students[MAX_STUDENTS];
int studentCount = 0;

/* ===========================
   Add Student
   =========================== */
void addStudent(void)
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("\nRegistry is full!\n");
        return;
    }

    Student s;

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    getchar();

    /* Check duplicate ID */
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == s.id)
        {
            printf("Student ID already exists.\n");
            return;
        }
    }

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Major: ");
    fgets(s.major, sizeof(s.major), stdin);
    s.major[strcspn(s.major, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    printf("Enter Credits: ");
    scanf("%d", &s.credits);

    students[studentCount++] = s;

    printf("\nStudent added successfully!\n");
}

/* ===========================
   Display All Students
   =========================== */
void displayAllStudents(void)
{
    if (studentCount == 0)
    {
        printf("\nNo students found.\n");
        return;
    }

    printf("\n===============================================================\n");
    printf("%-6s %-25s %-18s %-5s %-8s\n",
           "ID", "Name", "Major", "GPA", "Credits");
    printf("===============================================================\n");

    for (int i = 0; i < studentCount; i++)
    {
        printf("%-6d %-25s %-18s %-5.2f %-8d\n",
               students[i].id,
               students[i].name,
               students[i].major,
               students[i].gpa,
               students[i].credits);
    }

    printf("===============================================================\n");
}

/* ===========================
   Search by Student ID
   =========================== */
void searchByID(void)
{
    int id;
    int found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("\nStudent Found\n");
            printf("-----------------------------\n");
            printf("ID      : %d\n", students[i].id);
            printf("Name    : %s\n", students[i].name);
            printf("Major   : %s\n", students[i].major);
            printf("GPA     : %.2f\n", students[i].gpa);
            printf("Credits : %d\n", students[i].credits);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

/* ===========================
   Search by GPA
   =========================== */
void findByGPA(void)
{
    float minGPA;
    int found = 0;

    printf("\nEnter minimum GPA: ");
    scanf("%f", &minGPA);

    printf("\nStudents with GPA >= %.2f\n\n", minGPA);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].gpa >= minGPA)
        {
            printf("%d | %s | %s | %.2f | %d\n",
                   students[i].id,
                   students[i].name,
                   students[i].major,
                   students[i].gpa,
                   students[i].credits);

            found = 1;
        }
    }

    if (!found)
        printf("No matching students found.\n");
}
/* ===========================
   Search by Major
   =========================== */
void findByMajor(void)
{
    char major[50];
    int found = 0;

    getchar();  // Clear input buffer

    printf("\nEnter Major: ");
    fgets(major, sizeof(major), stdin);
    major[strcspn(major, "\n")] = '\0';

    printf("\nStudents in %s\n\n", major);

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].major, major) == 0)
        {
            printf("%d | %s | %.2f | %d\n",
                   students[i].id,
                   students[i].name,
                   students[i].gpa,
                   students[i].credits);

            found = 1;
        }
    }

    if (!found)
        printf("No students found in that major.\n");
}

/* ===========================
   Save Students to File
   =========================== */
void saveStudentsToFile(void)
{
    FILE *file = fopen(DATA_FILE, "w");

    if (file == NULL)
    {
        printf("Error: Could not save data.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        fprintf(file,
                "%d|%s|%s|%.2f|%d\n",
                students[i].id,
                students[i].name,
                students[i].major,
                students[i].gpa,
                students[i].credits);
    }

    fclose(file);

    printf("\nSaved %d student(s) successfully.\n", studentCount);
}

/* ===========================
   Load Students from File
   =========================== */
void loadStudentsFromFile(void)
{
    FILE *file = fopen(DATA_FILE, "r");

    if (file == NULL)
    {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }

    studentCount = 0;

    while (studentCount < MAX_STUDENTS)
    {
        Student s;

        int result = fscanf(file,
                            "%d|%99[^|]|%49[^|]|%f|%d\n",
                            &s.id,
                            s.name,
                            s.major,
                            &s.gpa,
                            &s.credits);

        if (result != 5)
            break;

        students[studentCount++] = s;
    }

    fclose(file);

    printf("Loaded %d student(s).\n", studentCount);
}
