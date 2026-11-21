#include <stdio.h>

int main(void)
{
    long long first, second;

    if (scanf("%lld %lld", &first, &second) != 2) {
        return 1;
    }

    unsigned long long a = first < 0
        ? 0ULL - (unsigned long long)first
        : (unsigned long long)first;
    unsigned long long b = second < 0
        ? 0ULL - (unsigned long long)second
        : (unsigned long long)second;

    while (b != 0) {
        unsigned long long remainder = a % b;
        a = b;
        b = remainder;
    }

    printf("%llu\n", a);
    return 0;
}