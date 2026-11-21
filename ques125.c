#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 4096

int main(int argc, char *argv[])
{
    const char *filename = argc > 1 ? argv[1] : "data.txt";
    char input[TEXT_SIZE];

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read appended text.\n");
        return 1;
    }
    input[strcspn(input, "\r\n")] = '\0';

    const char *text = input;
    const char *label = "User Input:";
    if (strncmp(text, label, strlen(label)) == 0) {
        text += strlen(label);
        while (*text == ' ' || *text == '\t') {
            ++text;
        }
    }

    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Failed to open file for appending");
        return 1;
    }

    int write_failed = 0;
    if (fseek(file, 0, SEEK_END) != 0) {
        write_failed = 1;
    } else {
        long file_size = ftell(file);
        if (file_size < 0) {
            write_failed = 1;
        } else if (file_size > 0) {
            if (fseek(file, -1, SEEK_END) != 0) {
                write_failed = 1;
            } else {
                int last_character = fgetc(file);
                if (last_character == EOF && ferror(file)) {
                    write_failed = 1;
                }
                if (!write_failed && fseek(file, 0, SEEK_END) != 0) {
                    write_failed = 1;
                }
                if (!write_failed && last_character != '\n' &&
                    fputc('\n', file) == EOF) {
                    write_failed = 1;
                }
            }
        }
    }

    if (!write_failed &&
        (fputs(text, file) == EOF || fputc('\n', file) == EOF)) {
        write_failed = 1;
    }

    if (fclose(file) != 0) {
        write_failed = 1;
    }
    if (write_failed) {
        fprintf(stderr, "Failed to append text to file.\n");
        return 1;
    }

    printf("File updated successfully with appended text.\n");
    return 0;
}