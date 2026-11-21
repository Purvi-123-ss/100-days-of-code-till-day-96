#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main(void)
{
    char input[4096];
    int nums[MAX_SIZE];
    long long answer[MAX_SIZE];
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

    long long prefix_product = 1;
    for (int i = 0; i < count; ++i) {
        answer[i] = prefix_product;
        prefix_product *= nums[i];
    }

    long long suffix_product = 1;
    for (int i = count - 1; i >= 0; --i) {
        answer[i] *= suffix_product;
        suffix_product *= nums[i];
    }

    printf("[");
    for (int i = 0; i < count; ++i) {
        if (i > 0) {
            printf(",");
        }
        printf("%lld", answer[i]);
    }
    printf("]\n");
    return 0;
}