#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char name[MAX_LENGTH + 1];

    if (fgets(name, sizeof(name), stdin) == NULL) {
        return 1;
    }

    name[strcspn(name, "\r\n")] = '\0';

    int length = (int)strlen(name);
    while (length > 0 &&
           (name[length - 1] == ' ' || name[length - 1] == '\t')) {
        --length;
    }
    name[length] = '\0';

    int surname_start = 0;
    for (int i = 0; i < length; ++i) {
        if (name[i] == ' ' || name[i] == '\t') {
            surname_start = i + 1;
        }
    }

    if (surname_start == 0) {
        printf("%s\n", name);
        return 0;
    }

    int at_word_start = 1;
    int printed = 0;
    for (int i = 0; i < surname_start; ++i) {
        char ch = name[i];

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

    printf(" ");
    printf("%s\n", name + surname_start);
    return 0;
}