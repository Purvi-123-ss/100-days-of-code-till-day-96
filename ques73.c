#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int rows;
    int columns;
    int matrix[MAX_SIZE][MAX_SIZE];
    long long row_sums[MAX_SIZE];

    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > MAX_SIZE ||
        columns < 1 || columns > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < rows; ++i) {
        row_sums[i] = 0;
        for (int j = 0; j < columns; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
            row_sums[i] += matrix[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%lld", row_sums[i]);
    }
    printf("\n");

    return 0;
}