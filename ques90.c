#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '\n' || text[i] == '\r') {
            break;
        }

        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (char)(text[i] - 'A' + 'a');
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (char)(text[i] - 'a' + 'A');
        }
    }

    for (int i = 0; text[i] != '\0' &&
                    text[i] != '\n' && text[i] != '\r'; ++i) {
        putchar(text[i]);
    }
    printf("\n");

    return 0;
}