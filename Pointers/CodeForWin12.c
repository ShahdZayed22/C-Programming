#include <stdio.h>

int main() {
    // C Program to Find Length of String Using Pointers

    char str[] = "Hello, World!";
    char *ptr = str;
    int length = 0;

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    printf("Length of the string: %d\n", length);

    return 0;
}
