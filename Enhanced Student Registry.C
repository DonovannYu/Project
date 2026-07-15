#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct
{
    int id;
    char name[50];
    char major[50];
    float gpa;
    int credits;
} Student;

/* Function Prototypes */
void loadFromFile(Student student[], int *count);
void saveToFile(Student student[], int count);
void addStudent(Student student[], int *count);
void displayStudents(Student student[], int count);
void searchID(Student student[], int count);
void searchGPA(Student student[], int count);
void searchMajor(Student student[], int count);

int main()
{
    Student student[MAX];
    int count = 0;
    int choice;

    /* Load existing records */
    loadFromFile(student, &count);

    do
    {
        printf("\n==============================\n");
        printf("   DR. SANTOS STUDENT REGISTRY\n");
        printf("==============================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by ID\n");
        printf("4. Search by GPA\n");
        printf("5. Search by Major\n");
        printf("6. Save and Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent(student, &count);
                break;

            case 2:
                displayStudents(student, count);
                break;

            case 3:
                searchID(student, count);
                break;

            case 4:
                searchGPA(student, count);
                break;

            case 5:
                searchMajor(student, count);
                break;

            case 6:
                saveToFile(student, count);
                printf("Records saved.\n");
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 6);

    return 0;
}

/*========================================*/

void loadFromFile(Student student[], int *count)
{
    FILE *fp;
    int i;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        *count = 0;
        return;
    }

    fread(count, sizeof(int), 1, fp);

    for(i = 0; i < *count; i++)
    {
        fread(&student[i], sizeof(Student), 1, fp);
    }

    fclose(fp);

    printf("\n%d student record(s) loaded.\n", *count);
}

/*========================================*/

void saveToFile(Student student[], int count)
{
    FILE *fp;
    int i;

    fp = fopen("students.dat", "wb");

    if(fp == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);

    for(i = 0; i < count; i++)
    {
        fwrite(&student[i], sizeof(Student), 1, fp);
    }

    fclose(fp);
}

/*========================================*/

void addStudent(Student student[], int *count)
{
    if(*count >= MAX)
    {
        printf("Student list is full.\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &student[*count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", student[*count].name);

    printf("Enter Major: ");
    scanf(" %[^\n]", student[*count].major);

    printf("Enter GPA: ");
    scanf("%f", &student[*count].gpa);

    printf("Enter Credits: ");
    scanf("%d", &student[*count].credits);

    (*count)++;

    printf("Student added successfully.\n");
}

/*========================================*/

void displayStudents(Student student[], int count)
{
    int i;

    if(count == 0)
    {
        printf("No student records.\n");
        return;
    }

    printf("\n========== STUDENT LIST ==========\n");

    for(i = 0; i < count; i++)
    {
        printf("\nStudent #%d\n", i + 1);
        printf("ID      : %d\n", student[i].id);
        printf("Name    : %s\n", student[i].name);
        printf("Major   : %s\n", student[i].major);
        printf("GPA     : %.2f\n", student[i].gpa);
        printf("Credits : %d\n", student[i].credits);
    }
}

/*========================================*/

void searchID(Student student[], int count)
{
    int id;
    int i;
    int found = 0;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(student[i].id == id)
        {
            printf("\nStudent Found\n");
            printf("ID      : %d\n", student[i].id);
            printf("Name    : %s\n", student[i].name);
            printf("Major   : %s\n", student[i].major);
            printf("GPA     : %.2f\n", student[i].gpa);
            printf("Credits : %d\n", student[i].credits);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student not found.\n");
}

/*========================================*/

void searchGPA(Student student[], int count)
{
    float minimum;
    int i;
    int found = 0;

    printf("Minimum GPA: ");
    scanf("%f", &minimum);

    printf("\nStudents with GPA >= %.2f\n", minimum);

    for(i = 0; i < count; i++)
    {
        if(student[i].gpa >= minimum)
        {
            printf("--------------------------------\n");
            printf("ID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Major: %s\n", student[i].major);
            printf("GPA: %.2f\n", student[i].gpa);

            found = 1;
        }
    }

    if(found == 0)
        printf("No students found.\n");
}

/*========================================*/

void searchMajor(Student student[], int count)
{
    char major[50];
    int i;
    int total = 0;

    printf("Enter Major: ");
    scanf(" %[^\n]", major);

    printf("\nStudents in %s\n", major);

    for(i = 0; i < count; i++)
    {
        if(strcmp(student[i].major, major) == 0)
        {
            printf("--------------------------------\n");
            printf("ID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("GPA: %.2f\n", student[i].gpa);
            printf("Credits: %d\n", student[i].credits);

            total++;
        }
    }

    printf("\nTotal Students: %d\n", total);
}
