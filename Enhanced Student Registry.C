#include "student_registry.h"


// ===============================
// ADD STUDENT FUNCTION
// ===============================
void addStudent(Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[*count].id);

    getchar(); // clear input buffer

    printf("Enter Student Name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';


    printf("Enter Major: ");
    fgets(students[*count].major, sizeof(students[*count].major), stdin);
    students[*count].major[strcspn(students[*count].major, "\n")] = '\0';


    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);


    printf("Enter Credits Completed: ");
    scanf("%d", &students[*count].credits);


    (*count)++;

    printf("\nStudent added successfully!\n");
}



// ===============================
// DISPLAY ALL STUDENTS
// ===============================
void displayAllStudents(Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo student records found.\n");
        return;
    }


    printf("\n===== STUDENT LIST =====\n");


    for (int i = 0; i < count; i++)
    {
        printf("\nStudent #%d\n", i + 1);
        printf("ID      : %d\n", students[i].id);
        printf("Name    : %s\n", students[i].name);
        printf("Major   : %s\n", students[i].major);
        printf("GPA     : %.2f\n", students[i].gpa);
        printf("Credits : %d\n", students[i].credits);
    }
}



// ===============================
// SEARCH STUDENT BY ID
// ===============================
void searchByID(Student students[], int count)
{
    int id;
    int found = 0;


    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);


    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nStudent Found!\n");

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
    {
        printf("\nStudent not found.\n");
    }
}



// ===============================
// FIND STUDENTS BY GPA
// ===============================
void findByGPA(Student students[], int count)
{
    float gpa;
    int found = 0;


    printf("\nEnter minimum GPA: ");
    scanf("%f", &gpa);


    printf("\nStudents with GPA %.2f or higher:\n", gpa);


    for (int i = 0; i < count; i++)
    {
        if (students[i].gpa >= gpa)
        {
            printf("\nID: %d", students[i].id);
            printf("\nName: %s", students[i].name);
            printf("\nMajor: %s", students[i].major);
            printf("\nGPA: %.2f\n", students[i].gpa);

            found = 1;
        }
    }


    if (!found)
    {
        printf("\nNo students matched the GPA requirement.\n");
    }
}



// ===============================
// FIND STUDENTS BY MAJOR
// ===============================
void findByMajor(Student students[], int count)
{
    char major[50];
    int found = 0;


    getchar();

    printf("\nEnter Major to search: ");
    fgets(major, sizeof(major), stdin);

    major[strcspn(major, "\n")] = '\0';



    printf("\nStudents under %s:\n", major);



    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].major, major) == 0)
        {
            printf("\nID: %d", students[i].id);
            printf("\nName: %s", students[i].name);
            printf("\nGPA: %.2f\n", students[i].gpa);

            found = 1;
        }
    }


    if (!found)
    {
        printf("\nNo students found under that major.\n");
    }
}



// ===============================
// SAVE STUDENTS TO FILE
// ===============================
void saveStudentsToFile(Student students[], int count)
{
    FILE *file;


    file = fopen(FILE_NAME, "wb");


    if (file == NULL)
    {
        printf("\nError opening file for saving.\n");
        return;
    }


    fwrite(&count, sizeof(int), 1, file);


    fwrite(students, sizeof(Student), count, file);


    fclose(file);


    printf("\nStudent records saved successfully!\n");
}



// ===============================
// LOAD STUDENTS FROM FILE
// ===============================
void loadStudentsFromFile(Student students[], int *count)
{
    FILE *file;


    file = fopen(FILE_NAME, "rb");


    if (file == NULL)
    {
        printf("\nNo existing data file found. Starting fresh.\n");
        *count = 0;
        return;
    }



    fread(count, sizeof(int), 1, file);


    fread(students, sizeof(Student), *count, file);



    fclose(file);



    printf("\nLoaded %d students from file.\n", *count);
}
