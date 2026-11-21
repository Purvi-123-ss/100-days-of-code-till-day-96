#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    int value;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &value) != 1) {
            return 1;
        }
    }

    int target;
    if (scanf("%d", &target) != 1) {
        return 1;
    }

    int found_index = -1;

    rewind(stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &value) == 1 && value == target && found_index == -1) {
            found_index = i;
        }
    }

    if (found_index == -1) {
        printf("-1\n");
    } else {
        printf("Found at index %d\n", found_index);
    }

    return 0;
}