#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    int positive = 0;
    int negative = 0;
    int zero = 0;

    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }

        if (value > 0) {
            ++positive;
        } else if (value < 0) {
            ++negative;
        } else {
            ++zero;
        }
    }

    printf("Positive=%d, Negative=%d, Zero=%d\n", positive, negative, zero);
    return 0;
}