#include <stdio.h>

#define BUFFER_SIZE 1024

int main(void)
{
    FILE *file = fopen("info.txt", "r");
    if (file == NULL) {
        perror("Failed to open info.txt");
        return 1;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (fputs(line, stdout) == EOF) {
            perror("Failed to print file contents");
            fclose(file);
            return 1;
        }
    }

    if (ferror(file)) {
        perror("Failed to read info.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Failed to close info.txt");
        return 1;
    }

    return 0;
}