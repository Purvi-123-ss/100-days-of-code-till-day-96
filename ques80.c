#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int rows1;
    int columns1;
    int rows2;
    int columns2;
    long long first[MAX_SIZE][MAX_SIZE];
    long long second[MAX_SIZE][MAX_SIZE];
    long long result[MAX_SIZE][MAX_SIZE];

    if (scanf("%d %d", &rows1, &columns1) != 2 ||
        rows1 < 1 || rows1 > MAX_SIZE ||
        columns1 < 1 || columns1 > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns1; ++j) {
            if (scanf("%lld", &first[i][j]) != 1) {
                return 1;
            }
        }
    }

    if (scanf("%d %d", &rows2, &columns2) != 2 ||
        rows2 < 1 || rows2 > MAX_SIZE ||
        columns2 < 1 || columns2 > MAX_SIZE ||
        columns1 != rows2) {
        return 1;
    }

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < columns2; ++j) {
            if (scanf("%lld", &second[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            if (j > 0) {
                printf(" ");
            }
            printf("%lld", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}