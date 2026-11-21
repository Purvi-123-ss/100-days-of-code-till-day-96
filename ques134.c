#include <stdio.h>
#include <string.h>

enum Result {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main(void)
{
    char input[16];
    enum Result result;

    if (scanf("%15s", input) != 1) {
        fprintf(stderr, "Error: Could not read a result.\n");
        return 1;
    }

    if (strcmp(input, "SUCCESS") == 0) {
        result = SUCCESS;
    } else if (strcmp(input, "FAILURE") == 0) {
        result = FAILURE;
    } else if (strcmp(input, "TIMEOUT") == 0) {
        result = TIMEOUT;
    } else {
        fprintf(stderr, "Error: Invalid result.\n");
        return 1;
    }

    switch (result) {
        case SUCCESS:
            puts("Operation successful");
            break;
        case FAILURE:
            puts("Operation failed");
            break;
        case TIMEOUT:
            puts("Operation timed out");
            break;
    }

    return 0;
}