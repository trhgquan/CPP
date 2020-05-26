/**
 * Example for using dynamic string,
 * Resources used:
 * - sth_else/CS102/pointer_and_memory_allocation/allocation_string.c
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    char ID[8]; // fixed style aka static array.
    char* name; // flexible size, max 50 character.
    double GPA;
} typedef Student;

/**
 * Input one student.
 * @param student pointer to a Student variable.
 */
void inputAStudent(Student* student) {
    // Read student ID.
    printf("Student ID: "); scanf("%s", student->ID);
    fflush(stdin);

    // Read student Name.
    char temp[51];
    printf("Student name: ");
    gets(temp); // Old C version, unsafe.

    // Allocates memory for student.name
    student->name = (char*)malloc(strlen(temp));
    // copy student name from temp.
    strcpy(student->name, temp);
    fflush(stdin);

    // Read student GPA.
    printf("Student GPA: "); scanf("%lf", &student->GPA);
}

/**
 * Output one student.
 * @param student Student variable to output.
 */
void outputAStudent(Student student) {
    printf("Student ID: %s\n", student.ID);
    printf("Student name: %s\n", student.name);
    printf("Student GPA: %.2lf", student.GPA);
}

int main() {
    // Declare a new student.
    Student s;
    // Input the student.
    inputAStudent(&s);
    // Output the student.
    outputAStudent(s);
    return 0;
}
