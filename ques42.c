#include <stdio.h>

int main(void)
{
    long long number;
    unsigned long long sum = 0;

    if (scanf("%lld", &number) != 1) {
        return 1;
    }

    if (number > 1) {
        for (long long divisor = 1; divisor <= number / 2; ++divisor) {
            if (number % divisor == 0) {
                sum += (unsigned long long)divisor;
            }
        }
    }

    if (number > 1 && sum == (unsigned long long)number) {
        printf("Perfect Number\n");
    } else {
        printf("Not a Perfect Number\n");
    }

    return 0;
}