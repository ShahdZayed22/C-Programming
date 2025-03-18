#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Reverse an array using pointers
    int Array[] = {1, 2, 3, 4};
    int size = sizeof(Array) / sizeof(Array[0]);

    for (int i = 0; i < size / 2; i++) {
        int temp = *(Array + i);
        *(Array + i) = *(Array + (size - 1 - i));
        *(Array + (size - 1 - i)) = temp;
    }

    printf("Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(Array + i));
    }

    printf("\n");

    return 0;
}
