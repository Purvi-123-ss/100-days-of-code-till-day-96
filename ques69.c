#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int n;
    int numbers[MAX_SIZE];

    if (scanf("%d", &n) != 1 || n < 2 || n > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    int largest = numbers[0];
    int second_largest = -2147483647 - 1;

    for (int i = 1; i < n; ++i) {
        if (numbers[i] > largest) {
            second_largest = largest;
            largest = numbers[i];
        } else if (numbers[i] < largest &&
                   (second_largest == -2147483647 - 1 ||
                    numbers[i] > second_largest)) {
            second_largest = numbers[i];
        }
    }

    if (second_largest == -2147483647 - 1) {
        printf("-1\n");
    } else {
        printf("%d\n", second_largest);
    }

    return 0;
}