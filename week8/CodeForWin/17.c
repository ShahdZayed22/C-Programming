#include <stdio.h>

int main(){
    // Write a C program to sort array using pointers.

    int arr[] = {2, 7, 5, 9, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr1, *ptr2, temporary;

    for (ptr1 = arr; ptr1 < arr + size - 1; ptr1++){
        for (ptr2 = ptr1 + 1; ptr2 < arr + size; ptr2++){
            if (*ptr1 > *ptr2){
                temporary = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temporary;
            }
        }
    }
    printf("Sorted Array: ");
    for (ptr1 = arr; ptr1 < arr + size; ptr1++){
        printf("%d ",*ptr1 );
    }

    return 0;
}
