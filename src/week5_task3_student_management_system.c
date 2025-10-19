/*
 * week5_task3_student_management_system.c
 * Author: Eren Efe Ozkan
 * Student ID: 231ADB112
 * Description:
 * Simple in-memory "database" using an array of structs with file persistence.
 * Implements functions to load, save, add, and list student records.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);


int main(void) {
    Student students[MAX_STUDENTS]; 
    int count = 0; 
    int choice;

    // TODO: Load existing data from file using load_students()
    count = load_students(students);
    printf("Loaded %d student record(s) from %s.\n", count, DATA_FILE);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0; 
            continue;
        }
        getchar(); // clear newline

        switch (choice) {
            case 1:
                // TODO: Call list_students()
                list_students(students, count);
                break;
            case 2:
                // TODO: Call add_student()
                add_student(students, &count);
                break;
            case 3:
                // TODO: Call save_students() and exit loop
                save_students(students, count);
                printf("Data saved successfully. Exiting system.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}


// TODO: Implement load_students()
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        return 0; 
    }

    int count = 0;
    while (count < MAX_STUDENTS && 
           fscanf(fp, "%49[^,], %d, %f\n", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

// TODO: Implement save_students()
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w"); // "w" modu, dosyanın üzerine yazar
    if (fp == NULL) {
        perror("Error: Cannot open file for saving");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s, %d, %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }

    fclose(fp);
}

// TODO: Implement add_student()
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Maximum student capacity (%d) reached.\n", MAX_STUDENTS);
        return;
    }

    Student *new_student = &arr[*count]; 

    printf("--- Add New Student ---\n");
    
    printf("Enter Name (Max %d chars, single word/no spaces): ", NAME_LEN - 1);
    if (scanf("%49s", new_student->name) != 1) return; 

    printf("Enter ID: ");
    if (scanf("%d", &new_student->id) != 1) return;
    
    printf("Enter GPA: ");
    if (scanf("%f", &new_student->gpa) != 1) return;
    
    (*count)++;
    printf("Student added successfully. Total students: %d\n", *count);
    
    while (getchar() != '\n'); 
}

// TODO: Implement list_students()
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("The student list is currently empty.\n");
        return;
    }

    printf("\n--- Student List (%d Records) ---\n", count);
    printf("%-5s %-20s %-8s %-5s\n", "No.", "Name", "ID", "GPA");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-8d %-5.2f\n", 
               i + 1, 
               arr[i].name, 
               arr[i].id, 
               arr[i].gpa);
    }
    printf("----------------------------------------\n");
}
