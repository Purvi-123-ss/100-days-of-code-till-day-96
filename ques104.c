#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[4096];
    size_t length = fread(input, 1, sizeof(input) - 1, stdin);
    if (length == 0) {
        return 1;
    }
    input[length] = '\0';

    char *n_position = strstr(input, "n");
    char *cursor = n_position != NULL ? strchr(n_position, '=') : input;
    if (cursor == NULL) {
        cursor = input;
    } else {
        ++cursor;
    }

    char *end;
    long long n = strtoll(cursor, &end, 10);
    if (n <= 0) {
        printf("-1\n");
        return 0;
    }

    long long target = n * (n + 1) / 2;
    long long low = 1;
    long long high = n;
    long long pivot = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long left_sum = mid * (mid + 1) / 2;

        if (left_sum == target - mid * (mid - 1) / 2) {
            pivot = mid;
            break;
        }

        if (mid * mid < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", pivot);
    return 0;
}