#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    int even = 0;
    int odd = 0;

    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }

        if (value % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }

    printf("Even=%d, Odd=%d\n", even, odd);
    return 0;
}