#include <stdio.h>

int main() {
    // C Program to Find Reverse of a String Using Pointers

    char str[] = "Hello";
    char *start = str;
    char *end = str;

    while (*end) {
        end++;
    }
    end--;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Reversed String: %s\n", str);

    return 0;
}
