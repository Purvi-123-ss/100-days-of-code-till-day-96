#include <stdio.h>

int main()
{
    int first, second;
    char operator;

    printf("Enter an operator (+, -, *, /, %%): ");
    if (scanf(" %c", &operator) != 1)
    {
        printf("Invalid input.");
        return 1;
    }

    printf("Enter two integers: ");
    if (scanf("%d %d", &first, &second) != 2)
    {
        printf("Invalid input.");
        return 1;
    }

    switch (operator)
    {
        case '+':
            printf("%d + %d = %d", first, second, first + second);
            break;
        case '-':
            printf("%d - %d = %d", first, second, first - second);
            break;
        case '*':
            printf("%d * %d = %d", first, second, first * second);
            break;
        case '/':
            if (second == 0)
            {
                printf("Error: division by zero.");
            }
            else
            {
                printf("%d / %d = %.2f", first, second,
                       (double) first / second);
            }
            break;
        case '%':
            if (second == 0)
            {
                printf("Error: modulo by zero.");
            }
            else
            {
                printf("%d %% %d = %d", first, second, first % second);
            }
            break;
        default:
            printf("Invalid operator.");
    }

    return 0;
}