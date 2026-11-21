#include <stdio.h>

static void printGroup(int count)
{
    for (int i = 0; i < count; ++i) {
        printf("*\n");
    }
}

int main(void)
{
    printGroup(1);
    printf("\n");
    printGroup(3);
    printf("\n");
    printGroup(5);
    printf("\n");
    printGroup(3);
    printf("\n");
    printGroup(1);

    return 0;
}