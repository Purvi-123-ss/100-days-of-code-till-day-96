#include <stdio.h>

int main(void)
{
    int number;
    int original;
    long long reversed = 0;

    if (scanf("%d", &number) != 1) {
        return 1;
    }

    original = number;
    if (number >= 0) {
        while (number != 0) {
            reversed = reversed * 10 + number % 10;
            number /= 10;
        }
    }

    if (original >= 0 && reversed == original) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}