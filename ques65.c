#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int n;
    int numbers[MAX_SIZE];

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    int target;
    if (scanf("%d", &target) != 1) {
        return 1;
    }

    int left = 0;
    int right = n - 1;
    int found_index = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target) {
            found_index = middle;
            break;
        }
        if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    if (found_index == -1) {
        printf("-1\n");
    } else {
        printf("Found at index %d\n", found_index);
    }

    return 0;
}