#include "student_registry.h"


int main()
{
    Student students[MAX_STUDENTS];

    int studentCount = 0;
    int choice;


    // Load previous records when program starts
    loadStudentsFromFile(students, &studentCount);



    do
    {
        printf("\n====================================");
        printf("\n   DR. SANTOS' STUDENT REGISTRY");
        printf("\n====================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Student ID\n");
        printf("4. Find by GPA Threshold\n");
        printf("5. Find by Major\n");
        printf("6. Save & Exit\n");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);



        switch(choice)
        {

            case 1:
                addStudent(students, &studentCount);
                break;



            case 2:
                displayAllStudents(students, studentCount);
                break;



            case 3:
                searchByID(students, studentCount);
                break;



            case 4:
                findByGPA(students, studentCount);
                break;



            case 5:
                findByMajor(students, studentCount);
                break;



            case 6:
                saveStudentsToFile(students, studentCount);

                printf("\nThank you for using Student Registry!\n");
                break;



            default:
                printf("\nInvalid choice. Please try again.\n");

        }


    } while(choice != 6);



    return 0;
}
