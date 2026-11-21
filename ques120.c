#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 4095

int main(void)
{
    char text[MAX_LENGTH + 1];
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    text[strcspn(text, "\r\n")] = '\0';
    char *start = strchr(text, '=');
    if (start != NULL) {
        ++start;
        while (*start == ' ' || *start == '\t') {
            ++start;
        }
    } else {
        start = text;
    }

    int at_word_start = 1;
    for (char *p = start; *p != '\0'; ++p) {
        unsigned char ch = (unsigned char)*p;
        if (isspace(ch)) {
            at_word_start = 1;
        } else if (isalpha(ch)) {
            *p = (char)(at_word_start ? toupper(ch) : tolower(ch));
            at_word_start = 0;
        }
    }

    printf("%s\n", start);
    return 0;
}