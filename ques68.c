#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int n;
    int numbers[MAX_SIZE];

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    int position;
    if (scanf("%d", &position) != 1 ||
        position < 1 || position > n) {
        return 1;
    }

    int index = position - 1;
    for (int i = index; i < n - 1; ++i) {
        numbers[i] = numbers[i + 1];
    }
    --n;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
    }
    printf("\n");

    return 0;
}