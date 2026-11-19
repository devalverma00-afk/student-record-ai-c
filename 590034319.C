#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    long long sapId;
    int rollNo;
    char name[100];
    char phone[20];
    char email[100];
    int year;
    int semester;
    float sgpa[8];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

/* Function Declarations */
void addStudent();
void searchStudent();
float calculateCGPA(Student s);
void displayCGPA();
void averageCGPAByYear();
void displayAllStudents();
void deleteStudent();
void sortBySAPID();
void sortByName();
void academicAdvisor();
void displayStudent(Student s);


/* =========================================
   Calculate CGPA
   ========================================= */

float calculateCGPA(Student s) {

    float total = 0.0;
    int count = 0;

    for (int i = 0; i < 8; i++) {

        if (s.sgpa[i] > 0) {
            total = total + s.sgpa[i];
            count++;
        }
    }

    if (count == 0) {
        return 0.0;
    }

    return total / count;
}


/* =========================================
   Add Student
   ========================================= */

void addStudent() {

    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent limit reached!\n");
        return;
    }

    Student *s = &students[studentCount];

    printf("\n========== ADD STUDENT ==========\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &s->sapId);

    /* Check duplicate SAP ID */
    for (int i = 0; i < studentCount; i++) {

        if (students[i].sapId == s->sapId) {
            printf("\nStudent with this SAP ID already exists!\n");
            return;
        }
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Phone Number: ");
    scanf("%19s", s->phone);

    printf("Enter Email ID: ");
    scanf("%99s", s->email);

    printf("Enter Year (1-4): ");
    scanf("%d", &s->year);

    if (s->year < 1 || s->year > 4) {
        printf("\nInvalid year!\n");
        return;
    }

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &s->semester);

    if (s->semester < 1 || s->semester > 8) {
        printf("\nInvalid semester!\n");
        return;
    }

    /* Initialize all SGPA values */
    for (int i = 0; i < 8; i++) {
        s->sgpa[i] = 0.0;
    }

    printf("\nEnter SGPA for completed semesters:\n");

    for (int i = 0; i < s->semester; i++) {

        do {

            printf("Semester %d SGPA (0-10): ", i + 1);
            scanf("%f", &s->sgpa[i]);

            if (s->sgpa[i] < 0 || s->sgpa[i] > 10) {
                printf("Invalid SGPA. Enter between 0 and 10.\n");
            }

        } while (s->sgpa[i] < 0 || s->sgpa[i] > 10);
    }

    studentCount++;

    printf("\nStudent added successfully!\n");
}


/* =========================================
   Display One Student
   ========================================= */

void displayStudent(Student s) {

    printf("\n----------------------------------------\n");

    printf("SAP ID           : %lld\n", s.sapId);
    printf("Roll Number      : %d\n", s.rollNo);
    printf("Name             : %s\n", s.name);
    printf("Phone Number     : %s\n", s.phone);
    printf("Email ID         : %s\n", s.email);
    printf("Year             : %d\n", s.year);
    printf("Current Semester : %d\n", s.semester);

    printf("\nSGPA Details:\n");

    for (int i = 0; i < s.semester; i++) {
        printf("Semester %d SGPA  : %.2f\n",
               i + 1,
               s.sgpa[i]);
    }

    printf("CGPA             : %.2f\n", calculateCGPA(s));

    printf("----------------------------------------\n");
}


/* =========================================
   Search Student
   ========================================= */

void searchStudent() {

    long long sapId;

    printf("\n========== SEARCH STUDENT ==========\n");

    printf("Enter SAP ID to search: ");
    scanf("%lld", &sapId);

    for (int i = 0; i < studentCount; i++) {

        if (students[i].sapId == sapId) {

            printf("\nStudent Found!\n");

            displayStudent(students[i]);

            return;
        }
    }

    printf("\nStudent not found!\n");
}


/* =========================================
   Display CGPA
   ========================================= */

void displayCGPA() {

    long long sapId;

    printf("\n========== CALCULATE CGPA ==========\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &sapId);

    for (int i = 0; i < studentCount; i++) {

        if (students[i].sapId == sapId) {

            float cgpa = calculateCGPA(students[i]);

            printf("\nStudent Name : %s\n", students[i].name);
            printf("CGPA         : %.2f\n", cgpa);

            return;
        }
    }

    printf("\nStudent not found!\n");
}


/* =========================================
   Average CGPA By Year
   ========================================= */

void averageCGPAByYear() {

    printf("\n========== AVERAGE CGPA BY YEAR ==========\n");

    for (int year = 1; year <= 4; year++) {

        float total = 0.0;
        int count = 0;

        for (int i = 0; i < studentCount; i++) {

            if (students[i].year == year) {

                total += calculateCGPA(students[i]);

                count++;
            }
        }

        if (count > 0) {

            printf("Year %d Average CGPA: %.2f\n",
                   year,
                   total / count);

        } else {

            printf("Year %d: No student records available.\n",
                   year);
        }
    }
}


/* =========================================
   Display All Students
   ========================================= */

void displayAllStudents() {

    if (studentCount == 0) {

        printf("\nNo student records available!\n");

        return;
    }

    printf("\n========== ALL STUDENT RECORDS ==========\n");

    for (int i = 0; i < studentCount; i++) {

        printf("\nStudent %d\n", i + 1);

        displayStudent(students[i]);
    }
}


/* =========================================
   Delete Student
   ========================================= */

void deleteStudent() {

    long long sapId;

    printf("\n========== DELETE STUDENT ==========\n");

    printf("Enter SAP ID to delete: ");
    scanf("%lld", &sapId);

    for (int i = 0; i < studentCount; i++) {

        if (students[i].sapId == sapId) {

            printf("\nDeleting student: %s\n",
                   students[i].name);

            /*
             Move every student after the deleted
             student one position to the left.
            */

            for (int j = i; j < studentCount - 1; j++) {

                students[j] = students[j + 1];
            }

            studentCount--;

            printf("Student deleted successfully!\n");

            return;
        }
    }

    printf("\nStudent not found!\n");
}


/* =========================================
   Sort By SAP ID
   ========================================= */

void sortBySAPID() {

    if (studentCount == 0) {

        printf("\nNo student records available!\n");

        return;
    }

    Student temp;

    for (int i = 0; i < studentCount - 1; i++) {

        for (int j = 0; j < studentCount - i - 1; j++) {

            if (students[j].sapId > students[j + 1].sapId) {

                temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by SAP ID successfully!\n");

    displayAllStudents();
}


/* =========================================
   Sort By Name
   ========================================= */

void sortByName() {

    if (studentCount == 0) {

        printf("\nNo student records available!\n");

        return;
    }

    Student temp;

    for (int i = 0; i < studentCount - 1; i++) {

        for (int j = 0; j < studentCount - i - 1; j++) {

            if (strcmp(students[j].name,
                       students[j + 1].name) > 0) {

                temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Name successfully!\n");

    displayAllStudents();
}


/* =========================================
   AI-Assisted Academic Advisor
   ========================================= */

void academicAdvisor() {

    long long sapId;

    printf("\n========== AI-ASSISTED ACADEMIC ADVISOR ==========\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &sapId);

    for (int i = 0; i < studentCount; i++) {

        if (students[i].sapId == sapId) {

            float cgpa = calculateCGPA(students[i]);

            printf("\nStudent : %s\n", students[i].name);
            printf("CGPA    : %.2f\n", cgpa);

            printf("\nAcademic Recommendation:\n");

            if (cgpa >= 9.0) {

                printf("Excellent Performance!\n");
                printf("Maintain your current study pattern.\n");

            } else if (cgpa >= 7.5) {

                printf("Good Performance!\n");
                printf("Keep working consistently and focus on weaker subjects.\n");

            } else if (cgpa >= 6.0) {

                printf("Needs Improvement!\n");
                printf("Focus more on subjects with lower SGPA and practice regularly.\n");

            } else {

                printf("Requires Immediate Attention!\n");
                printf("Create a structured study plan and seek academic guidance.\n");
            }

            return;
        }
    }

    printf("\nStudent not found!\n");
}


/* =========================================
   Main Function
   ========================================= */

int main() {

    int choice;

    do {

        printf("\n========================================\n");
        printf(" STUDENT RECORD AND RESULT MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Calculate Student CGPA\n");
        printf("4. Average CGPA by Year\n");
        printf("5. Display All Students\n");
        printf("6. Delete Student\n");
        printf("7. Sort Students by SAP ID\n");
        printf("8. Sort Students by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("10. Exit\n");

        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                displayCGPA();
                break;

            case 4:
                averageCGPAByYear();
                break;

            case 5:
                displayAllStudents();
                break;

            case 6:
                deleteStudent();
                break;

            case 7:
                sortBySAPID();
                break;

            case 8:
                sortByName();
                break;

            case 9:
                academicAdvisor();
                break;

            case 10:
                printf("\nThank you for using the program.\n");
                printf("Program terminated successfully.\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1-10.\n");
        }

    } while (choice != 10);

    return 0;
}