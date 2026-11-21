#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main(void)
{
    char input[4096];
    int nums[MAX_SIZE];
    int count = 0;

    size_t input_length = fread(input, 1, sizeof(input) - 1, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    char *bracket = strchr(input, '[');
    char *close_bracket = bracket != NULL ? strchr(bracket, ']') : NULL;
    char *cursor = bracket != NULL && close_bracket != NULL
                       ? bracket + 1
                       : input;
    char *limit = close_bracket != NULL ? close_bracket : input + input_length;

    while (cursor < limit && count < MAX_SIZE) {
        while (cursor < limit &&
               !isdigit((unsigned char)*cursor) &&
               *cursor != '-') {
            ++cursor;
        }
        if (cursor >= limit) {
            break;
        }

        char *end;
        nums[count++] = (int)strtol(cursor, &end, 10);
        cursor = end;
    }

    for (int i = 0; i < count; ++i) {
        int previous_greater = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] > nums[i]) {
                previous_greater = nums[j];
                break;
            }
        }

        if (i > 0) {
            printf(", ");
        }
        printf("%d", previous_greater);
    }
    printf("\n");
    return 0;
}