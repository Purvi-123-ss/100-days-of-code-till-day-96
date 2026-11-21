#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    int length = 0;
    while (text[length] != '\0' &&
           text[length] != '\n' &&
           text[length] != '\r') {
        ++length;
    }

    for (int left = 0, right = length - 1; left < right; ++left, --right) {
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
    }

    for (int i = 0; i < length; ++i) {
        putchar(text[i]);
    }
    printf("\n");

    return 0;
}