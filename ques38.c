#include <stdio.h>

int main(void)
{
    long long number;
    unsigned long long value;
    unsigned long long sum = 0;

    if (scanf("%lld", &number) != 1) {
        return 1;
    }

    value = number < 0
        ? 0ULL - (unsigned long long)number
        : (unsigned long long)number;

    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }

    printf("%llu\n", sum);
    return 0;
}