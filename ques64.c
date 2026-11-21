#include <stdio.h>

int main(void)
{
    long long number;
    int frequency[10] = {0};

    if (scanf("%lld", &number) != 1) {
        return 1;
    }

    if (number < 0) {
        number = -number;
    }

    do {
        ++frequency[number % 10];
        number /= 10;
    } while (number != 0);

    int most_frequent_digit = 0;
    for (int digit = 1; digit <= 9; ++digit) {
        if (frequency[digit] > frequency[most_frequent_digit]) {
            most_frequent_digit = digit;
        }
    }

    printf("%d\n", most_frequent_digit);
    return 0;
}