/*
 * Lab 3, Task 3
 * Student Name: Eren Efe Özkan
 * Student ID: 231ADB112
 *
 * Manual string handling:
 *   - my_strlen(const char *str)   // count characters (not including '\0')
 *   - my_strcpy(char *dest, const char *src) // copy string into dest
 *
 * Rules:
 *   - Do not use <string.h> functions
 *   - Use loops or pointer arithmetic
 *   - Ensure dest has enough space
 */

#include <stdio.h>

// Prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
  char text[] = "hello";
  int len = my_strlen(text);
  printf("Length: %d\n", len);

  char buffer[100];
  my_strcpy(buffer, text);
  printf("Copied string: %s\n", buffer);

  return 0;
}

// Implementations

int my_strlen(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

void my_strcpy(char *dest, const char *src) {
  int i = 0;
  while (1) {
    dest[i] = src[i];
    if (src[i] == '\0') break;
    i++;
  }
}
