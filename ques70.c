#include <stdio.h>

#define MAX_SIZE 100

static void reverse(int numbers[], int left, int right)
{
    while (left < right) {
        int temporary = numbers[left];
        numbers[left] = numbers[right];
        numbers[right] = temporary;
        ++left;
        --right;
    }
}

int main(void)
{
    int n;
    int k;
    int numbers[MAX_SIZE];

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    if (scanf("%d", &k) != 1 || k < 0) {
        return 1;
    }

    k %= n;
    reverse(numbers, 0, n - 1);
    reverse(numbers, 0, k - 1);
    reverse(numbers, k, n - 1);

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
    }
    printf("\n");

    return 0;
}