#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];
    int spaces = 0;
    int digits = 0;
    int special = 0;

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        char character = text[i];

        if (character == '\n' || character == '\r') {
            break;
        }

        if (character == ' ') {
            ++spaces;
        } else if (character >= '0' && character <= '9') {
            ++digits;
        } else if (!((character >= 'A' && character <= 'Z') ||
                     (character >= 'a' && character <= 'z'))) {
            ++special;
        }
    }

    printf("Spaces=%d, Digits=%d, Special=%d\n",
           spaces, digits, special);
    return 0;
}