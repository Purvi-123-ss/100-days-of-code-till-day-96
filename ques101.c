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

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    char *bracket = strchr(input, '[');
    char *close_bracket = bracket ? strchr(bracket, ']') : NULL;
    char *target_position = strstr(input, "target");

    if (target_position != NULL) {
        target_position = strchr(target_position, '=');
    }

    if (bracket != NULL && close_bracket != NULL) {
        const char *cursor = bracket + 1;
        while (cursor < close_bracket) {
            if (count >= MAX_SIZE) {
                break;
            }
            nums[count++] = read_integer(&cursor);
            ++cursor;
        }

        if (target_position != NULL) {
            const char *target_cursor = target_position + 1;
            int target = read_integer(&target_cursor);

            int first = -1;
            int last = -1;
            int low = 0;
            int high = count - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] >= target) {
                    if (nums[mid] == target) {
                        first = mid;
                    }
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            low = 0;
            high = count - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] <= target) {
                    if (nums[mid] == target) {
                        last = mid;
                    }
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            printf("%d,%d\n", first, last);
            return 0;
        }
    }

    const char *cursor = input;
    int values[MAX_SIZE];
    int value_count = 0;
    while (*cursor != '\0' && value_count < MAX_SIZE) {
        while (*cursor != '\0' && !isdigit((unsigned char)*cursor) &&
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
        printf("-1,-1\n");
        return 0;
    }

    int target = values[value_count - 1];
    count = value_count - 1;
    for (int i = 0; i < count; ++i) {
        nums[i] = values[i];
    }

    int first = -1;
    int last = -1;
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) {
                first = mid;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    low = 0;
    high = count - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) {
                last = mid;
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d,%d\n", first, last);
    return 0;
}