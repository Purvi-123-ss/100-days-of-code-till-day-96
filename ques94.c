#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char sentence[MAX_LENGTH + 1];
    char longest[MAX_LENGTH + 1] = "";
    char current[MAX_LENGTH + 1];

    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    int longest_length = 0;
    int i = 0;

    while (sentence[i] != '\0') {
        while (sentence[i] == ' ' || sentence[i] == '\t' ||
               sentence[i] == '\n' || sentence[i] == '\r') {
            ++i;
        }

        int start = i;
        while (sentence[i] != '\0' && sentence[i] != ' ' &&
               sentence[i] != '\t' && sentence[i] != '\n' &&
               sentence[i] != '\r') {
            ++i;
        }

        int length = i - start;
        if (length > longest_length) {
            strncpy(current, sentence + start, (size_t)length);
            current[length] = '\0';
            strcpy(longest, current);
            longest_length = length;
        }
    }

    printf("%s\n", longest);
    return 0;
}