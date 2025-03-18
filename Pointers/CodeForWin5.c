#include <stdio.h>
#include <stdlib.h>

int main() {
    //Write a C program to copy one array to another using pointers.

    int Array1[] = {1, 2, 3, 4, 5};
    int size = sizeof(Array1) / sizeof(Array1[0]);
    int Array2[size];

    for (int i = 0; i < size; i++)
    {
        *(Array2 + i) = *(Array1 + i);
    }

    printf("Copied Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(Array2 + i));  
    }

    printf("\n"); 

    return 0;
}
