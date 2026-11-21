#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char sentence[MAX_LENGTH + 1];

    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    int word_start = 0;

    for (int i = 0;; ++i) {
        if (sentence[i] == '\0' || sentence[i] == '\n' ||
            sentence[i] == '\r' ||
            sentence[i] == ' ' || sentence[i] == '\t') {
            for (int j = i - 1; j >= word_start; --j) {
                putchar(sentence[j]);
            }

            if (sentence[i] == '\0' || sentence[i] == '\n' ||
                sentence[i] == '\r') {
                break;
            }

            putchar(sentence[i]);
            ++i;
            while (sentence[i] == ' ' || sentence[i] == '\t') {
                putchar(sentence[i]);
                ++i;
            }
            word_start = i;
            --i;
        }
    }

    printf("\n");
    return 0;
}