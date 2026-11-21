#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    text[strcspn(text, "\r\n")] = '\0';
    int length = (int)strlen(text);
    int first = 1;

    for (int start = 0; start < length; ++start) {
        for (int end = start; end < length; ++end) {
            if (!first) {
                putchar(',');
            }

            for (int i = start; i <= end; ++i) {
                putchar(text[i]);
            }
            first = 0;
        }
    }

    printf("\n");
    return 0;
}