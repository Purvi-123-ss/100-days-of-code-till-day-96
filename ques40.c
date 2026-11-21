#include <stdio.h>

int main(void)
{
    long long binary, value, complement = 0;
    long long place = 1;
    int digits = 0;

    if (scanf("%lld", &binary) != 1 || binary < 0) {
        fprintf(stderr, "Enter a non-negative binary number.\n");
        return 1;
    }

    value = binary;

    if (value == 0) {
        complement = 1;
        digits = 1;
    } else {
        while (value > 0) {
            int digit = (int)(value % 10);

            if (digit != 0 && digit != 1) {
                fprintf(stderr, "Input must contain only 0s and 1s.\n");
                return 1;
            }

            if (digit == 0) {
                complement += place;
            }

            digits++;
            value /= 10;
            if (value > 0) {
                place *= 10;
            }
        }
    }

    printf("%0*lld\n", digits, complement);
    return 0;
}