#include <limits.h>
#include <stdio.h>

static unsigned long long magnitude(long long value)
{
    return value < 0
        ? 0ULL - (unsigned long long)value
        : (unsigned long long)value;
}

int main(void)
{
    long long first, second;
    unsigned long long a, b, x, y;

    if (scanf("%lld %lld", &first, &second) != 2) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    a = magnitude(first);
    b = magnitude(second);
    if (a == 0 || b == 0) {
        printf("0\n");
        return 0;
    }

    x = a;
    y = b;
    while (y != 0) {
        unsigned long long remainder = x % y;
        x = y;
        y = remainder;
    }

    a /= x;
    if (a > ULLONG_MAX / b) {
        fprintf(stderr, "The LCM is too large to represent.\n");
        return 1;
    }

    printf("%llu\n", a * b);
    return 0;
}