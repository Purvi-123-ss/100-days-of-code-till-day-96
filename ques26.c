#include <stdio.h>

int main()
{
    int n;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input.");
        return 1;
    }

    for (int number = 1; number <= n; number++)
    {
        printf("%d ", number);
    }

    return 0;
}