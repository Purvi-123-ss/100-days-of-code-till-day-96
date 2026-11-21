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
    int nums[MAX_SIZE + 1];
    int count = 0;
    int target;

    size_t input_length = fread(input, 1, sizeof(input) - 1, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    char *bracket = strchr(input, '[');
    char *close_bracket = bracket != NULL ? strchr(bracket, ']') : NULL;

    if (bracket != NULL && close_bracket != NULL) {
        const char *cursor = bracket + 1;
        const char *limit = close_bracket;
        while (count < MAX_SIZE &&
               parse_integer(&cursor, limit, &nums[count])) {
            ++count;
        }

        char *target_position = strstr(close_bracket, "target");
        if (target_position != NULL) {
            char *equals = strchr(target_position, '=');
            if (equals == NULL) {
                printf("-1 -1\n");
                return 0;
            }
            const char *target_cursor = equals + 1;
            const char *input_limit = input + input_length;
            if (!parse_integer(&target_cursor, input_limit, &target)) {
                printf("-1 -1\n");
                return 0;
            }
        } else {
            const char *target_cursor = close_bracket + 1;
            const char *input_limit = input + input_length;
            if (!parse_integer(&target_cursor, input_limit, &target)) {
                printf("-1 -1\n");
                return 0;
            }
        }
    } else {
        const char *cursor = input;
        const char *limit = input + input_length;
        while (count < MAX_SIZE + 1 &&
               parse_integer(&cursor, limit, &nums[count])) {
            ++count;
        }
        if (count < 2) {
            printf("-1 -1\n");
            return 0;
        }
        target = nums[count - 1];
        --count;
    }

    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if ((long long)nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("-1 -1\n");
    return 0;
}