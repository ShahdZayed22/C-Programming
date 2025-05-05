#include <stdio.h>

int main() {
    char a[1000000];
    int i, sum = 0;

    scanf("%s", a);

    for (i = 0; a[i] != '\0'; i++) {
        sum += a[i] - '0';
    }

    printf("%d\n", sum);

    return 0;
}
