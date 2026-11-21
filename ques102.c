#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

static int read_integer(const char **cursor)
{
    while (**cursor != '\0' && !isdigit((unsigned char)**cursor) &&
           **cursor != '-') {
        ++*cursor;
    }

    char *end;
    int value = (int)strtol(*cursor, &end, 10);
    if (end == *cursor) {
        return 0;
    }
    *cursor = end;
    return value;
}

int main(void)
{
    char input[4096];
    int nums[MAX_SIZE];
    int count = 0;

    size_t length = fread(input, 1, sizeof(input) - 1, stdin);
    if (length == 0) {
        return 1;
    }
    input[length] = '\0';

    char *bracket = strchr(input, '[');
    char *close_bracket = bracket ? strchr(bracket, ']') : NULL;
    int target;

    if (bracket != NULL && close_bracket != NULL) {
        const char *cursor = bracket + 1;
        while (cursor < close_bracket && count < MAX_SIZE) {
            nums[count++] = read_integer(&cursor);
            ++cursor;
        }

        char *x_position = strstr(input, "x");
        if (x_position != NULL) {
            x_position = strchr(x_position, '=');
        }
        if (x_position != NULL) {
            const char *target_cursor = x_position + 1;
            target = read_integer(&target_cursor);
        } else {
            const char *cursor = input;
            int values[MAX_SIZE];
            int value_count = 0;
            while (*cursor != '\0' && value_count < MAX_SIZE) {
                while (*cursor != '\0' &&
                       !isdigit((unsigned char)*cursor) &&
                       *cursor != '-') {
                    ++cursor;
                }
                if (*cursor == '\0') {
                    break;
                }
                char *end;
                values[value_count++] = (int)strtol(cursor, &end, 10);
                cursor = end;
            }
            if (value_count == 0) {
                return 1;
            }
            target = values[value_count - 1];
        }
    } else {
        const char *cursor = input;
        int values[MAX_SIZE];
        int value_count = 0;
        while (*cursor != '\0' && value_count < MAX_SIZE) {
            while (*cursor != '\0' &&
                   !isdigit((unsigned char)*cursor) &&
                   *cursor != '-') {
                ++cursor;
            }
            if (*cursor == '\0') {
                break;
            }
            char *end;
            values[value_count++] = (int)strtol(cursor, &end, 10);
            cursor = end;
        }
        if (value_count < 2) {
            printf("-1\n");
            return 0;
        }
        target = values[value_count - 1];
        count = value_count - 1;
        for (int i = 0; i < count; ++i) {
            nums[i] = values[i];
        }
    }

    int low = 0;
    int high = count - 1;
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}