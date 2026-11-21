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

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
    }
    printf("\n");

    return 0;
}