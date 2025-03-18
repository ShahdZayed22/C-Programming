#include <stdio.h>
#include <stdlib.h>

int main() {
    //Write a C program to swap two arrays using pointers.
    
    int Array1[] = {1, 2, 3, 4};
    int Array2[] = {5, 6, 7, 8};
    int size = sizeof(Array1) / sizeof(Array1[0]);

    for (int i = 0; i < size; i++)
    {
        int Temporary = *(Array1 + i);
        *(Array1 + i) = *(Array2 + i);
        *(Array2 + i) = Temporary;
    }

    printf("Array1 = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array1[i]);
    }

    printf("\nArray2 = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array2[i]);
    }

    printf("\n");

    return 0;
}
