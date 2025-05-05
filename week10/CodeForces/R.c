#include <stdio.h>
#include <string.h>

#define MAX 1000005

int main() {
    int n, i = 0;
    char s[MAX];
    scanf("%d", &n);
    scanf("%s", s);

    int score = 0;

    while (i < n) {
        if (s[i] == 'V') {
            score += 5;
            i++;
        } else if (s[i] == 'W') {
            score += 2;
            i++;
        } else if (s[i] == 'X') {
            if (i + 1 < n) {
                // Remove next character by shifting left
                memmove(&s[i + 1], &s[i + 2], n - i - 1);
                n--;
            }
            i++;
        } else if (s[i] == 'Y') {
            if (i + 1 < n) {
                // Move next character to the end
                char temp = s[i + 1];
                memmove(&s[i + 1], &s[i + 2], n - i - 1);
                s[n - 1] = temp;
            }
            i++;
        } else if (s[i] == 'Z') {
            if (i + 1 < n) {
                if (s[i + 1] == 'V') {
                    score /= 5;
                    memmove(&s[i + 1], &s[i + 2], n - i - 1);
                    n--;
                } else if (s[i + 1] == 'W') {
                    score /= 2;
                    memmove(&s[i + 1], &s[i + 2], n - i - 1);
                    n--;
                }
            }
            i++;
        } else {
            i++;
        }
    }

    printf("%d\n", score);
    return 0;
}
