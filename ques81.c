#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    int length = 0;
    while (text[length] != '\0') {
        if (text[length] == '\n') {
            break;
        }
        ++length;
    }

    if (length > 0 && text[length - 1] == '\r') {
        --length;
    }

    printf("%d\n", length);
    return 0;
}