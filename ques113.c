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

static int compare_ints(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

int main(void)
{
    char input[4096];
    int values[MAX_SIZE + 1];
    int count = 0;
    int k;

    size_t input_length = fread(input, 1, sizeof(input) - 1, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    char *bracket = strchr(input, '[');
    char *close_bracket = NULL;
    while (bracket != NULL) {
        char *candidate_close = strchr(bracket, ']');
        if (candidate_close == NULL) {
            break;
        }

        int has_integer = 0;
        for (char *p = bracket + 1; p < candidate_close; ++p) {
            if (isdigit((unsigned char)*p) || *p == '-') {
                has_integer = 1;
                break;
            }
        }
        if (has_integer) {
            close_bracket = candidate_close;
            break;
        }
        bracket = strchr(candidate_close + 1, '[');
    }

    if (bracket != NULL && close_bracket != NULL) {
        const char *cursor = bracket + 1;
        const char *limit = close_bracket;
        while (count < MAX_SIZE &&
               parse_integer(&cursor, limit, &values[count])) {
            ++count;
        }

        char *k_position = strstr(close_bracket, "k");
        if (k_position != NULL) {
            char *equals = strchr(k_position, '=');
            if (equals == NULL) {
                printf("-1\n");
                return 0;
            }
            const char *k_cursor = equals + 1;
            const char *input_limit = input + input_length;
            if (!parse_integer(&k_cursor, input_limit, &k)) {
                printf("-1\n");
                return 0;
            }
        } else {
            const char *k_cursor = close_bracket + 1;
            const char *input_limit = input + input_length;
            if (!parse_integer(&k_cursor, input_limit, &k)) {
                printf("-1\n");
                return 0;
            }
        }
    } else {
        const char *cursor = input;
        const char *limit = input + input_length;
        while (count < MAX_SIZE + 1 &&
               parse_integer(&cursor, limit, &values[count])) {
            ++count;
        }
        if (count < 2) {
            printf("-1\n");
            return 0;
        }
        k = values[count - 1];
        --count;
    }

    if (k < 1 || k > count) {
        printf("-1\n");
        return 0;
    }

    qsort(values, (size_t)count, sizeof(values[0]), compare_ints);
    printf("%d\n", values[k - 1]);
    return 0;
}