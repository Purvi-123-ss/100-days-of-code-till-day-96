#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char first[MAX_LENGTH + 1];
    char second[MAX_LENGTH + 1];
    int count[256] = {0};

    if (fgets(first, sizeof(first), stdin) == NULL ||
        fgets(second, sizeof(second), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; first[i] != '\0'; ++i) {
        if (first[i] == '\n' || first[i] == '\r') {
            break;
        }
        ++count[(unsigned char)first[i]];
    }

    for (int i = 0; second[i] != '\0'; ++i) {
        if (second[i] == '\n' || second[i] == '\r') {
            break;
        }
        --count[(unsigned char)second[i]];
    }

    for (int i = 0; i < 256; ++i) {
        if (count[i] != 0) {
            printf("Not anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}