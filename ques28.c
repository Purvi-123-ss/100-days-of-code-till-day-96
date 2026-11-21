#include <limits.h>
#include <stdio.h>

int main(void)
{
    long long n;
    unsigned long long product = 1;

    printf("Enter n: ");
    if (scanf("%lld", &n) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    for (long long i = 2; i <= n; i += 2) {
        if (product > ULLONG_MAX / (unsigned long long)i) {
            fprintf(stderr, "The product is too large to represent.\n");
            return 1;
        }
        product *= (unsigned long long)i;
    }

    printf("Product of even numbers from 1 to %lld is %llu\n", n, product);
    return 0;
}