#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define TABLE_SIZE 2048

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

static unsigned int hash_int(int value)
{
    unsigned int hash = (unsigned int)value;
    hash ^= hash >> 16;
    hash *= 0x7feb352dU;
    hash ^= hash >> 15;
    hash *= 0x846ca68bU;
    hash ^= hash >> 16;
    return hash;
}

int main(void)
{
    char input[4096];
    int table[TABLE_SIZE];
    unsigned char occupied[TABLE_SIZE] = {0};

    size_t input_length = fread(input, 1, sizeof(input) - 1, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    char *open_bracket = strchr(input, '[');
    char *close_bracket = open_bracket != NULL
                              ? strchr(open_bracket, ']')
                              : NULL;
    char *equals = strchr(input, '=');
    const char *cursor = open_bracket != NULL && close_bracket != NULL
                             ? open_bracket + 1
                             : (equals != NULL ? equals + 1 : input);
    const char *limit = close_bracket != NULL
                            ? close_bracket
                            : input + input_length;

    int value;
    int processed = 0;
    while (processed < MAX_SIZE &&
           parse_integer(&cursor, limit, &value)) {
        unsigned int index = hash_int(value) & (TABLE_SIZE - 1);
        while (occupied[index] && table[index] != value) {
            index = (index + 1) & (TABLE_SIZE - 1);
        }
        if (occupied[index]) {
            printf("%d\n", value);
            return 0;
        }
        table[index] = value;
        occupied[index] = 1;
        ++processed;
    }

    printf("-1\n");
    return 0;
}