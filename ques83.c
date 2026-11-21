#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];
    int vowels = 0;
    int consonants = 0;

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        char character = text[i];

        if (character >= 'A' && character <= 'Z') {
            character = (char)(character - 'A' + 'a');
        }

        if (character == '\n' || character == '\r') {
            break;
        }

        if (character >= 'a' && character <= 'z') {
            if (character == 'a' || character == 'e' ||
                character == 'i' || character == 'o' ||
                character == 'u') {
                ++vowels;
            } else {
                ++consonants;
            }
        }
    }

    printf("Vowels=%d, Consonants=%d\n", vowels, consonants);
    return 0;
}