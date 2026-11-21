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
        printf("%c\n", text[i]);
    }

    return 0;
}