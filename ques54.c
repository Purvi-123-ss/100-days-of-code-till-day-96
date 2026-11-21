#include <stdio.h>

int main(void)
{
    for (int row = 0; row < 7; ++row) {
        int stars = row <= 3 ? 1 + 2 * row : 13 - 2 * row;
        int spaces = (7 - stars) / 2;

        for (int i = 0; i < spaces; ++i) {
            printf(" ");
        }
        for (int i = 0; i < stars; ++i) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}