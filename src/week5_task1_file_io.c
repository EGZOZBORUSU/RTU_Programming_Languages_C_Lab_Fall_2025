/*
 * week5_task1_file_io.c
 * Author: Eren Efe Ozkan
 * Student ID: 231ADB112
 * Description:
 * Demonstrates reading and writing data from text files using standard C I/O functions.
 * Includes BONUS features for dynamic filename input and line counting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy_s (güvenli) veya strcpy için

#define MAX_FILENAME_LEN 100
#define MAX_LINE_LEN 256

int main(void) {
    FILE *fp = NULL;
    char filename[MAX_FILENAME_LEN];
    char line[MAX_LINE_LEN];
    int line_count = 0;

    // BONUS: Ask user for filename
    printf("Enter the filename (e.g., data.txt): ");
    if (scanf("%99s", filename) != 1) { 
        printf("Error reading filename.\n");
        return 1;
    }
    
    
    printf("\n--- Writing to File: %s ---\n", filename);

    // TODO: 1. Open file for writing (mode = "w")
    fp = fopen(filename, "w");

    // TODO: 2. Check if file opened successfully
    if (fp == NULL) {
        perror("Error opening file for writing"); // Hata mesajını konsola yazdırır
        return 1;
    }

    // TODO: 3. Write 2–3 lines of text to the file using fprintf()
    fprintf(fp, "This is the first line of data.\n");
    fprintf(fp, "Second line containing student ID: %d.\n", 23112);
    fprintf(fp, "The third and final line for the test.\n");

    printf("Successfully wrote 3 lines to the file.\n");

    // TODO: 4. Close the file
    if (fclose(fp) == EOF) {
        perror("Error closing file after writing");
        return 1;
    }

    
    printf("\n--- Reading from File: %s ---\n", filename);

    // TODO: 5. Open file again for reading (mode = "r")
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // TODO: 6. Use fgets() in a loop to read and print each line to the console
    printf("File Content:\n");
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        printf("%s", line);
        // BONUS: count number of lines read
        line_count++; 
    }

    // TODO: 7. Close the file
    if (fclose(fp) == EOF) {
        perror("Error closing file after reading");
        return 1;
    }

    // BONUS: Print line count
    printf("\n--- Reading Complete ---\n");
    printf("Total lines read: %d\n", line_count);

    return 0;
}
