typedef struct
{
    int id;
    char name[50];
    char major[50];
    float gpa;
    int credits;
} Student;

void addStudent(Student student[], int *count);
void displayStudents(Student student[], int count);
void searchID(Student student[], int count);
void searchGPA(Student student[], int count);
void searchMajor(Student student[], int count);

void saveToFile(Student student[], int count);
void loadFromFile(Student student[], int *count);
