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
}        printf("==============================\n");
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
