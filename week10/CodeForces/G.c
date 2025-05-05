#include <stdio.h>
#include <string.h>

int main() {
    char a[1000000];
    int i;

    scanf("%s", a);

    for (i = 0; i < strlen(a); i++) {
        if (a[i] == ',') {
            printf(" ");
        } else {
            if (a[i] >= 'A' && a[i] <= 'Z') {
                printf("%c", a[i] + 32); 
            } else if (a[i] >= 'a' && a[i] <= 'z') {
                printf("%c", a[i] - 32); 
            }
        }
    }

    printf("\n");
    return 0;
}
