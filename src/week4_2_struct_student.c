/*
 * week4_2_struct_student.c
 * Author: Eren Efe Ozkan
 * Student ID: 231ADB112
 * Description:
 * Demonstrates defining and using a struct in C.
 * Students should define a 'Student' struct with fields like name, id, and grade.
 * Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h> // string fonksiyonları (strcpy) için

// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    // TODO: Declare one or more Student variables
    struct Student student1;
    struct Student student2;

    // TODO: Assign values (either manually or via scanf)
    
    strcpy(student1.name, "Eren Efe Ozkan"); 
    student1.id = 23112; 
    student1.grade = 3.85;

    printf("Enter details for Student 2:\n");
    
    printf("Name (Max 49 characters, no spaces): ");
    scanf("%49s", student2.name); 

    printf("ID: ");
    scanf("%d", &student2.id);
    
    printf("Grade (GPA): ");
    scanf("%f", &student2.grade);


    // TODO: Print struct contents using printf
    printf("\n--- Student Records ---\n");
    
    printf("Student 1:\n");
    printf("  Name: %s\n", student1.name);
    printf("  ID: %d\n", student1.id);
    printf("  Grade: %.2f\n", student1.grade);

    printf("Student 2:\n");
    printf("  Name: %s\n", student2.name);
    printf("  ID: %d\n", student2.id);
    printf("  Grade: %.2f\n", student2.grade);
    printf("-------------------------\n");

    return 0;
}
