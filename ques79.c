#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int rows;
    int columns;
    int matrix[MAX_SIZE][MAX_SIZE];

    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > MAX_SIZE ||
        columns < 1 || columns > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }

    int first = 1;
    for (int diagonal = 0; diagonal <= rows + columns - 2; ++diagonal) {
        if (diagonal % 2 == 0) {
            int row = diagonal < rows ? diagonal : rows - 1;
            int column = diagonal - row;
            for (; row >= 0 && column < columns; --row, ++column) {
                if (column >= 0) {
                    if (!first) {
                        printf(" ");
                    }
                    printf("%d", matrix[row][column]);
                    first = 0;
                }
            }
        } else {
            int row = diagonal < columns ? 0 : diagonal - columns + 1;
            int column = diagonal - row;
            for (; row < rows && column >= 0; ++row, --column) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", matrix[row][column]);
                first = 0;
            }
        }
    }
    printf("\n");

    return 0;
}