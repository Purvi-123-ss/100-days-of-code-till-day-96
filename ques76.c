#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int rows;
    int columns;
    int matrix[MAX_SIZE][MAX_SIZE];

    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > MAX_SIZE ||
        columns < 1 || columns > MAX_SIZE ||
        rows != columns) {
        return 1;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < columns; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("False\n");
                return 0;
            }
        }
    }

    printf("True\n");
    return 0;
}