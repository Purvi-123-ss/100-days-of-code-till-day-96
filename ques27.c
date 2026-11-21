#include <stdio.h>

int main()
{
    int n;
    long long sum = 0;

    printf("Enter the number of odd numbers: ");
    if (scanf("%d", &n) != 1 || n < 1)
    {
        printf("Invalid input.");
        return 1;
    }

    for (long long number = 1, count = 0; count < n; number += 2, count++)
    {
        sum += number;
    }

    printf("Sum of the first %d odd numbers = %lld", n, sum);

    return 0;
}