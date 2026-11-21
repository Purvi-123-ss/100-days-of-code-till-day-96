#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_SIZE 2048
#define NAME_SIZE 1024

static void trim(char **start, char **end)
{
    while (*start < *end && isspace((unsigned char)**start)) {
        ++*start;
    }
    while (*end > *start && isspace((unsigned char)(*end)[-1])) {
        --*end;
    }
}

int main(void)
{
    char input[INPUT_SIZE];
    char name[NAME_SIZE];
    int age;

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return 1;
    }

    input[strcspn(input, "\r\n")] = '\0';
    char *name_start = strstr(input, "Name:");
    name_start = name_start != NULL ? name_start + strlen("Name:") : input;

    char *age_label = strstr(name_start, "Age:");
    char *name_end = age_label;
    char *age_start = age_label != NULL
                          ? age_label + strlen("Age:")
                          : NULL;

    if (age_start == NULL) {
        char *comma = strrchr(name_start, ',');
        if (comma != NULL) {
            age_start = comma + 1;
            name_end = comma;
        } else {
            char *end = name_start + strlen(name_start);
            char *last_space = NULL;
            for (char *p = name_start; p < end; ++p) {
                if (isspace((unsigned char)*p)) {
                    last_space = p;
                }
            }
            if (last_space != NULL) {
                char *candidate = last_space + 1;
                char *parse_end;
                (void)strtol(candidate, &parse_end, 10);
                while (isspace((unsigned char)*parse_end)) {
                    ++parse_end;
                }
                if (parse_end != candidate && *parse_end == '\0') {
                    age_start = candidate;
                    name_end = last_space;
                }
            }
        }
    }

    if (age_start != NULL) {
        char *parse_end;
        long parsed_age = strtol(age_start, &parse_end, 10);
        if (parse_end == age_start) {
            fprintf(stderr, "Invalid age.\n");
            return 1;
        }
        age = (int)parsed_age;
    } else {
        if (scanf("%d", &age) != 1) {
            fprintf(stderr, "Failed to read age.\n");
            return 1;
        }
    }

    if (name_end == NULL) {
        name_end = name_start + strlen(name_start);
    }
    trim(&name_start, &name_end);
    if (name_start == name_end ||
        (size_t)(name_end - name_start) >= sizeof(name)) {
        fprintf(stderr, "Invalid name.\n");
        return 1;
    }
    memcpy(name, name_start, (size_t)(name_end - name_start));
    name[name_end - name_start] = '\0';

    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        perror("Failed to create info.txt");
        return 1;
    }

    int write_failed = fprintf(file, "Name: %s\nAge: %d\n", name, age) < 0;
    if (fclose(file) != 0) {
        write_failed = 1;
    }
    if (write_failed) {
        fprintf(stderr, "Failed to write data to info.txt.\n");
        return 1;
    }

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}