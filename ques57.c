#include <stdio.h>

int main(void)
{
    int n;
    long long sum = 0;

    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }
        sum += value;
    }

    printf("%lld\n", sum);
    return 0;
}