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

    int position;
    int value;
    if (scanf("%d %d", &position, &value) != 2 ||
        position < 1 || position > n + 1) {
        return 1;
    }

    int index = position - 1;
    for (int i = n; i > index; --i) {
        numbers[i] = numbers[i - 1];
    }
    numbers[index] = value;
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