#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int n1;
    int n2;
    int first[MAX_SIZE];
    int second[MAX_SIZE];
    int merged[MAX_SIZE * 2];

    if (scanf("%d", &n1) != 1 || n1 < 1 || n1 > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n1; ++i) {
        if (scanf("%d", &first[i]) != 1) {
            return 1;
        }
    }

    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX_SIZE ||
        n1 + n2 > MAX_SIZE * 2) {
        return 1;
    }

    for (int i = 0; i < n2; ++i) {
        if (scanf("%d", &second[i]) != 1) {
            return 1;
        }
    }

    for (int i = 0; i < n1; ++i) {
        merged[i] = first[i];
    }
    for (int i = 0; i < n2; ++i) {
        merged[n1 + i] = second[i];
    }

    for (int i = 0; i < n1 + n2; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", merged[i]);
    }
    printf("\n");

    return 0;
}