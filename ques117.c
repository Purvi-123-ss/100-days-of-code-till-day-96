#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

static int parse_integer(const char **cursor, const char *limit, int *value)
{
    while (*cursor < limit &&
           !isdigit((unsigned char)**cursor) && **cursor != '-') {
        ++*cursor;
    }
    if (*cursor >= limit) {
        return 0;
    }

    char *end;
    long parsed = strtol(*cursor, &end, 10);
    if (end == *cursor) {
        return 0;
    }
    *value = (int)parsed;
    *cursor = end;
    return 1;
}

int main(void)
{
    char input[4096];
    int first[MAX_SIZE];
    int second[MAX_SIZE];
    int first_count = 0;
    int second_count = 0;

    size_t input_length = fread(input, 1, sizeof(input) - 1, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    char *first_open = strchr(input, '[');
    char *first_close = first_open != NULL ? strchr(first_open, ']') : NULL;
    if (first_open == NULL || first_close == NULL) {
        return 1;
    }

    char *second_open = strchr(first_close + 1, '[');
    char *second_close = second_open != NULL ? strchr(second_open, ']') : NULL;
    if (second_open == NULL || second_close == NULL) {
        return 1;
    }

    const char *cursor = first_open + 1;
    const char *limit = first_close;
    while (first_count < MAX_SIZE &&
           parse_integer(&cursor, limit, &first[first_count])) {
        ++first_count;
    }

    cursor = second_open + 1;
    limit = second_close;
    while (second_count < MAX_SIZE &&
           parse_integer(&cursor, limit, &second[second_count])) {
        ++second_count;
    }

    int i = 0;
    int j = 0;
    int printed = 0;
    while (i < first_count || j < second_count) {
        int value;
        if (j >= second_count ||
            (i < first_count && first[i] <= second[j])) {
            value = first[i++];
        } else {
            value = second[j++];
        }

        if (printed) {
            putchar(' ');
        }
        printf("%d", value);
        printed = 1;
    }

    printf("\n");
    return 0;
}