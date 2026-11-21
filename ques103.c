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

    long long total = 0;
    for (int i = 0; i < count; ++i) {
        total += nums[i];
    }

    long long left_sum = 0;
    for (int i = 0; i < count; ++i) {
        long long right_sum = total - left_sum - nums[i];
        if (left_sum == right_sum) {
            printf("%d\n", i);
            return 0;
        }
        left_sum += nums[i];
    }

    printf("-1\n");
    return 0;
}