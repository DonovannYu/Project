#include <stdio.h>
#include <string.h>

#define MAX 500

typedef struct
{
    int id;
    char name[50];
    char major[50];
    float gpa;
    int credits;
} Student;

void addStudent(Student student[], int *count)
{
    if(*count >= MAX)
    {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter Student ID: ");
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

    printf("Student added successfully!\n");
}

void displayStudents(Student student[], int count)
{
    int i;

    if(count == 0)
    {
        printf("No students available.\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

    for(i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", student[i].id);
        printf("Name: %s\n", student[i].name);
        printf("Major: %s\n", student[i].major);
        printf("GPA: %.2f\n", student[i].gpa);
        printf("Credits: %d\n", student[i].credits);
    }
}

void searchID(Student student[], int count)
{
    int search;
    int i;
    int found = 0;

    printf("Enter Student ID: ");
    scanf("%d", &search);

    for(i = 0; i < count; i++)
    {
        if(student[i].id == search)
        {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Major: %s\n", student[i].major);
            printf("GPA: %.2f\n", student[i].gpa);
            printf("Credits: %d\n", student[i].credits);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student not found.\n");
}

void searchGPA(Student student[], int count)
{
    float minimum;
    int i;
    int found = 0;

    printf("Enter minimum GPA: ");
    scanf("%f", &minimum);

    for(i = 0; i < count; i++)
    {
        if(student[i].gpa >= minimum)
        {
            printf("\nID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("Major: %s\n", student[i].major);
            printf("GPA: %.2f\n", student[i].gpa);

            found = 1;
        }
    }

    if(found == 0)
        printf("No students found.\n");
}

void searchMajor(Student student[], int count)
{
    char search[50];
    int i;
    int total = 0;

    printf("Enter Major: ");
    scanf(" %[^\n]", search);

    for(i = 0; i < count; i++)
    {
        if(strcmp(student[i].major, search) == 0)
        {
            printf("\nID: %d\n", student[i].id);
            printf("Name: %s\n", student[i].name);
            printf("GPA: %.2f\n", student[i].gpa);
            printf("Credits: %d\n", student[i].credits);

            total++;
        }
    }

    printf("\nTotal Students in %s: %d\n", search, total);
}

int main()
{
    Student student[MAX];
    int count = 0;
    int choice;

    do
    {
        printf("\n===== STUDENT REGISTRY =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search by ID\n");
        printf("4. Search by GPA\n");
        printf("5. Search by Major\n");
        printf("6. Exit\n");
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
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 6);

    return 0;
}
