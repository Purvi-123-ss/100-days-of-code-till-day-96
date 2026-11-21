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
    int values[MAX_SIZE + 1];
    int deque[MAX_SIZE];
    int count = 0;
    int k;

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

    int front = 0;
    int back = 0;
    for (int i = 0; i < count; ++i) {
        while (front < back && deque[front] <= i - k) {
            ++front;
        }
        while (front < back && values[deque[back - 1]] <= values[i]) {
            --back;
        }
        deque[back++] = i;

        if (i >= k - 1) {
            if (i > k - 1) {
                putchar(' ');
            }
            printf("%d", values[deque[front]]);
        }
    }

    printf("\n");
    return 0;
}