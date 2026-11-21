#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    const char *filename = argc > 1 ? argv[1] : "sample.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    long long characters = 0;
    long long words = 0;
    long long lines = 0;
    int in_word = 0;
    int last_character = '\n';
    int character;

    while ((character = fgetc(file)) != EOF) {
        ++characters;
        last_character = character;

        if (character == '\n') {
            ++lines;
        }

        if (isspace((unsigned char)character)) {
            in_word = 0;
        } else if (!in_word) {
            ++words;
            in_word = 1;
        }
    }

    if (ferror(file)) {
        perror("Failed to read input file");
        fclose(file);
        return 1;
    }

    if (characters > 0 && last_character != '\n') {
        ++lines;
    }

    if (fclose(file) != 0) {
        perror("Failed to close input file");
        return 1;
    }

    printf("Characters: %lld\n", characters);
    printf("Words: %lld\n", words);
    printf("Lines: %lld\n", lines);
    return 0;
}