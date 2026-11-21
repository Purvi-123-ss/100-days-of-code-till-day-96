#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];
    int seen[26] = {0};

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (ch == '\n' || ch == '\r') {
            break;
        }

        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            if (seen[index]) {
                putchar(ch);
                printf("\n");
                return 0;
            }
            seen[index] = 1;
        }
    }

    printf("\n");
    return 0;
}