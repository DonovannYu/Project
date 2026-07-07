#include <stdio.h>
#include <string.h>

#define MAX 10

void addStudent(int id[], char name[][50], char major[][50],
                float gpa[], int credits[], int *count);

void displayStudents(int id[], char name[][50], char major[][50],
                     float gpa[], int credits[], int count);

void searchID(int id[], char name[][50], char major[][50],
              float gpa[], int credits[], int count);

void searchGPA(int id[], char name[][50], char major[][50],
               float gpa[], int credits[], int count);

void searchMajor(int id[], char name[][50], char major[][50],
                 float gpa[], int credits[], int count);

int main()
{
    int id[MAX];
    char name[MAX][50];
    char major[MAX][50];
    float gpa[MAX];
    int credits[MAX];

    int count = 0;
    int choice;

    do
    {
        printf("\n===== STUDENT REGISTRY =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by ID\n");
        printf("4. Search by GPA\n");
        printf("5. Search by Major\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent(id,name,major,gpa,credits,&count);
                break;

            case 2:
                displayStudents(id,name,major,gpa,credits,count);
                break;

            case 3:
                searchID(id,name,major,gpa,credits,count);
                break;

            case 4:
                searchGPA(id,name,major,gpa,credits,count);
                break;

            case 5:
                searchMajor(id,name,major,gpa,credits,count);
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

void addStudent(int id[], char name[][50], char major[][50],
                float gpa[], int credits[], int *count)
{
    if(*count >= MAX)
    {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d",&id[*count]);

    printf("Enter Name: ");
    scanf(" %[^\n]",name[*count]);

    printf("Enter Major: ");
    scanf(" %[^\n]",major[*count]);

    printf("Enter GPA: ");
    scanf("%f",&gpa[*count]);

    printf("Enter Credits: ");
    scanf("%d",&credits[*count]);

    (*count)++;

    printf("Student added successfully.\n");
}

void displayStudents(int id[], char name[][50], char major[][50],
                     float gpa[], int credits[], int count)
{
    int i;

    if(count==0)
    {
        printf("No students found.\n");
        return;
    }

    printf("\n===== STUDENTS =====\n");

    for(i=0;i<count;i++)
    {
        printf("\nStudent %d\n",i+1);
        printf("ID: %d\n",id[i]);
        printf("Name: %s\n",name[i]);
        printf("Major: %s\n",major[i]);
        printf("GPA: %.2f\n",gpa[i]);
        printf("Credits: %d\n",credits[i]);
    }
}

void searchID(int id[], char name[][50], char major[][50],
              float gpa[], int credits[], int count)
{
    int search,i,found=0;

    printf("Enter ID: ");
    scanf("%d",&search);

    for(i=0;i<count;i++)
    {
        if(id[i]==search)
        {
            printf("\nStudent Found\n");
            printf("ID: %d\n",id[i]);
            printf("Name: %s\n",name[i]);
            printf("Major: %s\n",major[i]);
            printf("GPA: %.2f\n",gpa[i]);
            printf("Credits: %d\n",credits[i]);

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Student not found.\n");
}

void searchGPA(int id[], char name[][50], char major[][50],
               float gpa[], int credits[], int count)
{
    float minimum;
    int i,found=0;

    printf("Minimum GPA: ");
    scanf("%f",&minimum);

    for(i=0;i<count;i++)
    {
        if(gpa[i]>=minimum)
        {
            printf("\nID: %d\n",id[i]);
            printf("Name: %s\n",name[i]);
            printf("Major: %s\n",major[i]);
            printf("GPA: %.2f\n",gpa[i]);
            printf("Credits: %d\n",credits[i]);

            found=1;
        }
    }

    if(found==0)
        printf("No students matched.\n");
}

void searchMajor(int id[], char name[][50], char major[][50],
                 float gpa[], int credits[], int count)
{
    char search[50];
    int i,total=0;

    printf("Enter Major: ");
    scanf(" %[^\n]",search);

    for(i=0;i<count;i++)
    {
        if(strcmp(major[i],search)==0)
        {
            printf("\nID: %d\n",id[i]);
            printf("Name: %s\n",name[i]);
            printf("GPA: %.2f\n",gpa[i]);
            printf("Credits: %d\n",credits[i]);

            total++;
        }
    }

    printf("\nTotal Students in %s: %d\n",search,total);
}
