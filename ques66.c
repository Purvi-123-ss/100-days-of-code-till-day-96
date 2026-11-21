#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int n;
    int numbers[MAX_SIZE];

    if (scanf("%d", &n) != 1 || n < 1 || n >= MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    int value;
    if (scanf("%d", &value) != 1) {
        return 1;
    }

    int position = 0;
    while (position < n && numbers[position] < value) {
        ++position;
    }

    for (int i = n; i > position; --i) {
        numbers[i] = numbers[i - 1];
    }
    numbers[position] = value;
    ++n;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
    }
    printf("\n");

    return 0;
}