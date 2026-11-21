#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char first[MAX_LENGTH + 1];
    char second[MAX_LENGTH + 1];
    char doubled[(MAX_LENGTH * 2) + 1];

    if (fgets(first, sizeof(first), stdin) == NULL ||
        fgets(second, sizeof(second), stdin) == NULL) {
        return 1;
    }

    first[strcspn(first, "\r\n")] = '\0';
    second[strcspn(second, "\r\n")] = '\0';

    size_t first_length = strlen(first);

    if (first_length != strlen(second) ||
        first_length > MAX_LENGTH) {
        printf("Not rotation\n");
        return 0;
    }

    strcpy(doubled, first);
    strcat(doubled, first);

    if (strstr(doubled, second) != NULL) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }

    return 0;
}