#include <stdio.h>

int main(void)
{
    long long number, original;
    unsigned long long sum = 0;

    if (scanf("%lld", &number) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    original = number;
    if (number >= 0) {
        do {
            int digit = (int)(number % 10);
            unsigned long long digit_factorial = 1;

            for (int i = 2; i <= digit; ++i) {
                digit_factorial *= (unsigned long long)i;
            }

            sum += digit_factorial;
            number /= 10;
        } while (number > 0);
    }

    if (original >= 0 && sum == (unsigned long long)original) {
        printf("Strong Number\n");
    } else {
        printf("Not a Strong Number\n");
    }

    return 0;
}