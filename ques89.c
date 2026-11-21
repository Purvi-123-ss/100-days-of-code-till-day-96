#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];
    char target;

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    if (scanf("%c", &target) != 1) {
        return 1;
    }

    int count = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '\n' || text[i] == '\r') {
            break;
        }
        if (text[i] == target) {
            ++count;
        }
    }

    printf("%d\n", count);
    return 0;
}