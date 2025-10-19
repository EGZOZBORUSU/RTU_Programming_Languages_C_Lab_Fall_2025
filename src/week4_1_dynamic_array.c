/*
 * week4_1_dynamic_array.c
 * Author: Eren Efe Ozkan
 * Student ID: 231ADB112
 * Description:
 * Demonstrates creation and usage of a dynamic array using malloc.
 * Students should allocate memory for an integer array, fill it with data,
 * compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;
    long long sum = 0; 
    float average = 0.0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size or input error.\n");
        return 1;
    }

    // TODO: Allocate memory for n integers using malloc
    arr = (int *)malloc(n * sizeof(int));

    // TODO: Check allocation success
    if (arr == NULL) {
        printf("Memory allocation failed! Exiting.\n");
        return 1; // Başarısızlık durumunda programdan çık
    }
    
    // TODO: Read n integers from user input and store in array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Stopping data entry.\n");
            // Belleği serbest bırakıp çıkış yapın
            free(arr);
            return 1; 
        }
        sum += arr[i];
    }

    // TODO: Compute sum and average
    // Ortalama hesaplama
    if (n > 0) {
        average = (float)sum / n; 
    }

    // TODO: Print the results
    printf("\n--- Results ---\n");
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total Sum: %lld\n", sum);
    printf("Average: %.2f\n", average);
    printf("-----------------\n");

    // TODO: Free allocated memory
    free(arr);
    printf("Dynamic memory successfully freed.\n");

    return 0;
}
