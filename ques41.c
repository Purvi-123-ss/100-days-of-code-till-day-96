#include <stdio.h>

int main(void)
{
    long long number;
    unsigned long long value, divisor = 1;
    unsigned long long first, last, middle, result;
    int is_negative;

    if (scanf("%lld", &number) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    is_negative = number < 0;
    value = is_negative
        ? 0ULL - (unsigned long long)number
        : (unsigned long long)number;

    while (value / divisor >= 10) {
        divisor *= 10;
    }

    first = value / divisor;
    last = value % 10;
    middle = (value % divisor) / 10;
    result = last * divisor + middle * 10 + first;

    printf("%s%llu\n", is_negative ? "-" : "", result);
    return 0;
}