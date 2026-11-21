#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char filename[256];
    unsigned long long vowels = 0;
    unsigned long long consonants = 0;
    int ch;
    FILE *file;

    printf("Filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        return 1;
    }

    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha((unsigned char)ch)) {
            switch (tolower((unsigned char)ch)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Error closing file");
        return 1;
    }

    printf("Vowels: %llu\n", vowels);
    printf("Consonants: %llu\n", consonants);
    return 0;
}