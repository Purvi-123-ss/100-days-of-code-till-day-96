#include <stdio.h>

int main()
{
    int lateDays;
    int fine = 0;

    printf("Enter the number of days late: ");
    scanf("%d", &lateDays);

    if (lateDays < 0)
    {
        printf("Invalid number of days.");
    }
    else if (lateDays > 30)
    {
        printf("Membership Cancelled.");
    }
    else
    {
        if (lateDays > 20)
        {
            fine += (lateDays - 20) * 6;
            lateDays = 20;
        }

        if (lateDays > 10)
        {
            fine += (lateDays - 10) * 4;
            lateDays = 10;
        }

        fine += lateDays * 2;
        printf("Library fine: ₹%d", fine);
    }

    return 0;
}