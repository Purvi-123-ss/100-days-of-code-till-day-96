#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char name[MAX_LENGTH + 1];

    if (fgets(name, sizeof(name), stdin) == NULL) {
        return 1;
    }

    int at_word_start = 1;
    int printed = 0;

    for (int i = 0; name[i] != '\0'; ++i) {
        char ch = name[i];

        if (ch == '\n' || ch == '\r') {
            break;
        }

        if (ch == ' ' || ch == '\t') {
            at_word_start = 1;
            continue;
        }

        if (at_word_start) {
            if (printed) {
                putchar('.');
            }

            if (ch >= 'a' && ch <= 'z') {
                ch = (char)(ch - 'a' + 'A');
            }

            putchar(ch);
            putchar('.');
            printed = 1;
            at_word_start = 0;
        }
    }

    printf("\n");
    return 0;
}