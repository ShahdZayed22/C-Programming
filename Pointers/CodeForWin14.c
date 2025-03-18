#include <stdio.h>

int main() {
    // C Program to Concatenate Two Strings Using Pointers

    char str1[50] = "Hello, ";
    char str2[] = "World!";
    char *ptr1 = str1;
    char *ptr2 = str2;

    while (*ptr1) {
        ptr1++;
    }

    while (*ptr2) {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    
    *ptr1 = '\0';

    printf("Concatenated String: %s\n", str1);

    return 0;
}
