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
    int values[MAX_SIZE];
    int count = 0;

    size_t input_length = fread(input, 1, sizeof(input) - 1, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    char *open_bracket = strchr(input, '[');
    char *close_bracket = open_bracket != NULL
                              ? strchr(open_bracket, ']')
                              : NULL;
    const char *cursor = open_bracket != NULL && close_bracket != NULL
                             ? open_bracket + 1
                             : input;
    const char *limit = close_bracket != NULL
                            ? close_bracket
                            : input + input_length;

    while (count < MAX_SIZE &&
           parse_integer(&cursor, limit, &values[count])) {
        ++count;
    }

    int missing = count;
    for (int i = 0; i < count; ++i) {
        missing ^= i ^ values[i];
    }

    printf("%d\n", missing);
    return 0;
}