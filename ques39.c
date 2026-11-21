#include <stdio.h>

int main(void)
{
    long long number;
    unsigned long long value;
    unsigned long long product = 1;

    if (scanf("%lld", &number) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    value = number < 0
        ? 0ULL - (unsigned long long)number
        : (unsigned long long)number;

    while (value > 0) {
        unsigned int digit = (unsigned int)(value % 10);
        if (digit % 2 != 0) {
            product *= digit;
        }
        value /= 10;
    }

    printf("%llu\n", product);
    return 0;
}