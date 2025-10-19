/*
 * week4_3_struct_database.c
 * Author: Eren Efe Ozkan
 * Student ID: 231ADB112
 * Description:
 * Simple in-memory "database" using an array of structs.
 * Students will use malloc to allocate space for multiple Student records,
 * then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL; 
    float total_grade = 0.0;
    float average_grade = 0.0;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number or input error.\n");
        return 1;
    }

    // TODO: Allocate memory for n Student structs using malloc
    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation for database failed! Exiting.\n");
        return 1;
    }

    // TODO: Read student data in a loop
    printf("\n--- Data Entry ---\n");
    for (int i = 0; i < n; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        
        
        printf("  Name (Max 49 characters, no spaces): ");
        scanf("%49s", (students + i)->name);

        printf("  ID: ");
        scanf("%d", &(students + i)->id);
        
        printf("  Grade (GPA): ");
        scanf("%f", &(students + i)->grade);
        
        total_grade += (students + i)->grade;
    }

    // Optional: Compute average grade or find top student
    if (n > 0) {
        average_grade = total_grade / n;
    }

    // TODO: Display all student records in formatted output
    printf("\n--- In-Memory Database Listing ---\n");
    printf("%-5s %-20s %-8s %-5s\n", "No.", "Name", "ID", "GPA");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-8d %-5.2f\n", 
               i + 1, 
               (students + i)->name, 
               (students + i)->id, 
               (students + i)->grade);
    }
    printf("----------------------------------------\n");
    printf("Total Students: %d\n", n);
    printf("Average Grade (GPA): %.2f\n", average_grade);
    printf("----------------------------------------\n");

    // TODO: Free allocated memory
    free(students);
    printf("Database memory successfully freed.\n");

    return 0;
}
