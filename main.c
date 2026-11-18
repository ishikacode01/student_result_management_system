
#include <stdio.h>
#include <string.h>
#define MAX 100
#define SUBJECTS 5

struct Student {
    int roll;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade[10];
};

// Calculate result
void calculateResult(struct Student *s) {
    s->total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        s->total += s->marks[i];
    }

    s->percentage = s->total / SUBJECTS;

    if (s->percentage >= 90)
        strcpy(s->grade, "A+");
    else if (s->percentage >= 80)
        strcpy(s->grade, "A");
    else if (s->percentage >= 70)
        strcpy(s->grade, "B");
    else if (s->percentage >= 60)
        strcpy(s->grade, "C");
    else if (s->percentage >= 40)
        strcpy(s->grade, "D");
    else
        strcpy(s->grade, "F");
}

// Add student
void addStudent(struct Student s[], int *n) {

    if (*n >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*n].roll);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[*n].name);

    printf("\nEnter marks in 5 subjects (out of 100):\n");

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s[*n].marks[i]);

        if (s[*n].marks[i] < 0 || s[*n].marks[i] > 100) {
            printf("Invalid marks! Enter marks between 0 and 100.\n");
            i--;
        }
    }

    calculateResult(&s[*n]);

    (*n)++;

    printf("\nStudent record added successfully!\n");
}

// Display all students
void displayStudents(struct Student s[], int n) {

    if (n == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\n-----------------------------\n");
        printf("Roll Number: %d\n", s[i].roll);
        printf("Student Name: %s\n", s[i].name);
        printf("Total Marks: %.2f / 500\n", s[i].total);
        printf("Percentage: %.2f%%\n", s[i].percentage);
        printf("Grade: %s\n", s[i].grade);

        if (s[i].percentage >= 40)
            printf("Result: PASS\n");
        else
            printf("Result: FAIL\n");
    }
}

// Search student
void searchStudent(struct Student s[], int n) {

    int roll, found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < n; i++) {

        if (s[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", s[i].name);
            printf("Total: %.2f / 500\n", s[i].total);
            printf("Percentage: %.2f%%\n", s[i].percentage);
            printf("Grade: %s\n", s[i].grade);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

// Main function
int main() {

    struct Student students[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n================================\n");
        printf(" STUDENT RESULT MANAGEMENT SYSTEM\n");
        printf("================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(students, &n);
                break;

            case 2:
                displayStudents(students, n);
                break;

            case 3:
                searchStudent(students, n);
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
