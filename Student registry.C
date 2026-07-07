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
