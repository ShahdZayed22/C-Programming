#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    scanf("%s", s);

    int len = strlen(s);
    int is_palindrome = 1;

    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
