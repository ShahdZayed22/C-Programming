#include <stdio.h>

int main() {
    // C Program to Multiply Two Matrices Using Pointers

    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            *(*(C + i) + j) = 0;
            for (int k = 0; k < 2; k++)
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
        }

    printf("Resultant Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", *(*(C + i) + j));
        printf("\n");
    }

    return 0;
}
