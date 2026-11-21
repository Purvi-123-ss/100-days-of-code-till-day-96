#include <stdio.h>

int main(void)
{
    long long number;

    if (scanf("%lld", &number) != 1 || number <= 0) {
        fprintf(stderr, "Enter a positive integer.\n");
        return 1;
    }

    for (long long factor = 1; factor <= number; ++factor) {
        if (number % factor == 0) {
            printf("%lld", factor);
            if (factor < number) {
                printf(" ");
            }
        }
    }
    printf("\n");

    return 0;
}