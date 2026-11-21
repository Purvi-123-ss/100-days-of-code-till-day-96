
#include <stdio.h>

int main()
{
    int num, remainder;
    long long binary = 0, place = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Please enter a positive number.");
    }
    else if (num == 0)
    {
        printf("Binary representation = 0");
    }
    else
    {
        while (num > 0)
        {
            remainder = num % 2;
            binary = binary + remainder * place;
            place = place * 10;
            num = num / 2;
        }

        printf("Binary representation = %lld", binary);
    }

    return 0;
}