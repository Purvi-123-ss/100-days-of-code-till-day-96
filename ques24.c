#include <stdio.h>

int main()
{
    int units;
    float bill;

    printf("Enter electricity units consumed: ");
    if (scanf("%d", &units) != 1 || units < 0)
    {
        printf("Invalid unit count.");
        return 1;
    }

    if (units <= 100)
    {
        bill = units * 5.0f;
    }
    else if (units <= 200)
    {
        bill = 100 * 5.0f + (units - 100) * 7.0f;
    }
    else if (units <= 300)
    {
        bill = 100 * 5.0f + 100 * 7.0f + (units - 200) * 10.0f;
    }
    else
    {
        bill = 100 * 5.0f + 100 * 7.0f + 100 * 10.0f
             + (units - 300) * 12.0f;
    }

    printf("Electricity bill: Rs. %.2f", bill);

    return 0;
}