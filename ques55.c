#include <stdio.h>

static int isPrime(long long number)
{
    if (number < 2) {
        return 0;
    }

    for (long long divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    long long n;
    int first = 1;

    if (scanf("%lld", &n) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    for (long long number = 2; number <= n; ++number) {
        if (isPrime(number)) {
            if (!first) {
                printf(" ");
            }
            printf("%lld", number);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}