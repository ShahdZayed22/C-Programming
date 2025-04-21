#include <stdio.h>

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = (*a > *b) ? (*a - *b) : (*b - *a);
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d\n", a, b);
    return 0;
}
