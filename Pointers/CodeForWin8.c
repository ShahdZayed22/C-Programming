#include <stdio.h>

int main() {

    // Write a C program to search an element in array using pointers.
    int arr[] = {10, 20, 30, 40, 50}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key, found = 0;
    int *ptr = arr; 

    printf("Enter the element you want to search for: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) 
    {
        if (*(ptr + i) == key) 
        { 
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}
