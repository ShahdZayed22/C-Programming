#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[n + 1];
    scanf("%s", s);

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            char temp = s[i];
            s[i] = s[min_index];
            s[min_index] = temp;
        }
    }

    printf("%s\n", s);

    return 0;
}
