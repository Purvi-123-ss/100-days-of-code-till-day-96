#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

    if (bracket == NULL || close_bracket == NULL) {
        printf("-1\n");
        return 0;
    }

    const char *cursor = bracket + 1;
    const char *limit = close_bracket;
    int value;
    if (!parse_integer(&cursor, limit, &value)) {
        printf("-1\n");
        return 0;
    }

    long long current_sum = value;
    long long max_sum = value;
    while (parse_integer(&cursor, limit, &value)) {
        if (current_sum < 0) {
            current_sum = value;
        } else {
            current_sum += value;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("%lld\n", max_sum);
    return 0;
}