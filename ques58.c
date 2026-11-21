#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int n;
    int numbers[MAX_SIZE];

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Enter an array size from 1 to %d.\n", MAX_SIZE);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            return 1;
        }
    }

    int minimum = numbers[0];
    int maximum = numbers[0];
    for (int i = 1; i < n; ++i) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    printf("Maximum: %d\nMinimum: %d\n", maximum, minimum);
    return 0;
}