#include <stdio.h>

int main(void)
{
    int n;
    double sum = 0.0;

    if (scanf("%d", &n) != 1 || n < 1) {
        fprintf(stderr, "Enter a positive number of terms.\n");
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        sum += (2.0 * i) / (4.0 * i - 1.0);
    }

    printf("Approximate sum: %.2f\n", sum);
    return 0;
}