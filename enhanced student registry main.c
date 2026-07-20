#include <stdio.h>
#include "student_registry.h"

void displayMenu(void)
{
    printf("\n=====================================\n");
    printf("     ENHANCED STUDENT REGISTRY\n");
    printf("=====================================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search by Student ID\n");
    printf("4. Find by GPA Threshold\n");
    printf("5. Find by Major\n");
    printf("6. Save & Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

int main(void)
{
    int choice;

    /* Load saved data at startup */
    loadStudentsFromFile();

    do
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayAllStudents();
                break;

            case 3:
                searchByID();
                break;

            case 4:
                findByGPA();
                break;

            case 5:
                findByMajor();
                break;

            case 6:
                saveStudentsToFile();
                printf("\nThank you for using Student Registry!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
