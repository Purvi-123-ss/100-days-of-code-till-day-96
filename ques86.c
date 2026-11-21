#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH + 1];

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    int length = 0;
    while (text[length] != '\0' &&
           text[length] != '\n' &&
           text[length] != '\r') {
        ++length;
    }

    int is_palindrome = 1;
    for (int left = 0, right = length - 1; left < right; ++left, --right) {
        if (text[left] != text[right]) {
            is_palindrome = 0;
            break;
        }
    }

    printf("%s\n", is_palindrome ? "Palindrome" : "Not palindrome");
    return 0;
}