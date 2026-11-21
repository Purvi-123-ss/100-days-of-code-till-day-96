#include <stdio.h>
#include <string.h>

#define PATH_SIZE 1024

static char *parse_filename(char *line, const char *label)
{
    line[strcspn(line, "\r\n")] = '\0';

    char *filename = strstr(line, label);
    filename = filename != NULL ? filename + strlen(label) : line;

    char *content_note = strstr(filename, " (Content:");
    if (content_note != NULL) {
        *content_note = '\0';
    }

    while (*filename == ' ' || *filename == '\t') {
        ++filename;
    }
    size_t length = strlen(filename);
    while (length > 0 &&
           (filename[length - 1] == ' ' || filename[length - 1] == '\t')) {
        filename[--length] = '\0';
    }
    return filename;
}

int main(int argc, char *argv[])
{
    char source_line[PATH_SIZE];
    char destination_line[PATH_SIZE];
    const char *source_path;
    const char *destination_path = "destination.txt";

    if (argc > 3) {
        fprintf(stderr, "Usage: %s [source [destination]]\n", argv[0]);
        return 1;
    }

    if (argc >= 2) {
        source_path = argv[1];
        if (argc == 3) {
            destination_path = argv[2];
        }
    } else {
        if (fgets(source_line, sizeof(source_line), stdin) == NULL) {
            fprintf(stderr, "Failed to read source filename.\n");
            return 1;
        }
        source_path = parse_filename(source_line, "Source File:");

        if (fgets(destination_line, sizeof(destination_line), stdin) != NULL) {
            destination_path =
                parse_filename(destination_line, "Destination File:");
        }
    }

    if (source_path[0] == '\0' || destination_path[0] == '\0') {
        fprintf(stderr, "Filenames cannot be empty.\n");
        return 1;
    }
    if (strcmp(source_path, destination_path) == 0) {
        fprintf(stderr, "Source and destination files must be different.\n");
        return 1;
    }

    FILE *source = fopen(source_path, "rb");
    if (source == NULL) {
        perror("Failed to open source file");
        return 1;
    }

    FILE *destination = fopen(destination_path, "wb");
    if (destination == NULL) {
        perror("Failed to open destination file");
        fclose(source);
        return 1;
    }

    int copy_failed = 0;
    int character;
    while ((character = fgetc(source)) != EOF) {
        if (fputc(character, destination) == EOF) {
            copy_failed = 1;
            break;
        }
    }
    if (ferror(source)) {
        copy_failed = 1;
    }

    if (fclose(source) != 0) {
        copy_failed = 1;
    }
    if (fclose(destination) != 0) {
        copy_failed = 1;
    }

    if (copy_failed) {
        fprintf(stderr, "Failed while copying file contents.\n");
        return 1;
    }

    printf("File copied successfully to %s\n", destination_path);
    return 0;
}