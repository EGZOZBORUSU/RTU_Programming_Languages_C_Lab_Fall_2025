/*
 * week5_task2_struct_save_load.c
 * Author: Eren Efe Ozkan
 * Student ID: 231ADB112
 * Description:
 * Demonstrates defining a struct and saving/loading a single structured record 
 * from a text file using fprintf and fscanf.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_FILENAME_LEN 100 

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice Smith");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student_record.txt"; 
    Student s_loaded; 

    printf("--- Saving Student Data ---\n");
    // TODO: Call save_student() to save student data to file
    save_student(s1, filename);
    printf("Student (Name: %s) data saved to %s.\n", s1.name, filename);
    
    printf("\n--- Loading Student Data ---\n");
    // TODO: Call load_student() to read data back into a new struct
    s_loaded = load_student(filename);

    // TODO: Print loaded data to confirm correctness
    printf("Data successfully loaded from file.\n");
    printf("Loaded Student Details:\n");
    printf("  Name: %s\n", s_loaded.name);
    printf("  Age: %d\n", s_loaded.age);
    printf("  GPA: %.2f\n", s_loaded.gpa);
    printf("---------------------------\n");


    return 0;
}

// TODO: Implement save_student()
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Error: Cannot open file for writing in save_student");
        return;
    }

    fprintf(fp, "%s, %d, %.2f\n", s.name, s.age, s.gpa);

    fclose(fp);
}

// TODO: Implement load_student()
Student load_student(const char *filename) {
    Student s = {"", 0, 0.0f}; // Hata durumunda boş/sıfır değer döndürmek için başlangıç değeri
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error: Cannot open file for reading in load_student");
        return s; 
    }

    if (fscanf(fp, "%49[^,], %d, %f", s.name, &s.age, &s.gpa) != 3) { 
        printf("Error: Could not read all 3 fields from file.\n");
        s.age = 0; s.gpa = 0.0f;
    }
    
    fclose(fp);

    return s;
}
