#include <ctype.h>
#include <stdio.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output;
    int ch;

    if (input == NULL) {
        perror("Error opening input.txt");
        return 1;
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Error opening output.txt");
        fclose(input);
        return 1;
    }

    while ((ch = fgetc(input)) != EOF) {
        if (fputc(toupper((unsigned char)ch), output) == EOF) {
            perror("Error writing output.txt");
            fclose(input);
            fclose(output);
            return 1;
        }
    }

    if (ferror(input)) {
        perror("Error reading input.txt");
        fclose(input);
        fclose(output);
        return 1;
    }

    if (fclose(input) == EOF) {
        perror("Error closing input.txt");
        fclose(output);
        return 1;
    }

    if (fclose(output) == EOF) {
        perror("Error closing output.txt");
        return 1;
    }

    return 0;
}