#include <stdio.h>

int main()
{
    float costPrice, sellingPrice, profitOrLoss, percentage;

    printf("Enter cost price: ");
    scanf("%f", &costPrice);

    printf("Enter selling price: ");
    scanf("%f", &sellingPrice);

    if (costPrice <= 0)
    {
        printf("Invalid cost price!");
    }
    else if (sellingPrice > costPrice)
    {
        profitOrLoss = sellingPrice - costPrice;
        percentage = (profitOrLoss / costPrice) * 100;
        printf("Profit = %.2f\n", profitOrLoss);
        printf("Profit Percentage = %.2f%%", percentage);
    }
    else if (sellingPrice < costPrice)
    {
        profitOrLoss = costPrice - sellingPrice;
        percentage = (profitOrLoss / costPrice) * 100;
        printf("Loss = %.2f\n", profitOrLoss);
        printf("Loss Percentage = %.2f%%", percentage);
    }
    else
    {
        printf("No Profit, No Loss");
    }

    return 0;
}