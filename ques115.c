#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_SIZE 4095

static void copy_trimmed(char *destination, const char *start, const char *end)
{
    while (start < end && isspace((unsigned char)*start)) {
        ++start;
    }
    while (end > start && isspace((unsigned char)end[-1])) {
        --end;
    }

    size_t length = (size_t)(end - start);
    memcpy(destination, start, length);
    destination[length] = '\0';
}

int main(void)
{
    char input[INPUT_SIZE + 1];
    char first[INPUT_SIZE + 1];
    char second[INPUT_SIZE + 1];

    size_t input_length = fread(input, 1, INPUT_SIZE, stdin);
    if (input_length == 0) {
        return 1;
    }
    input[input_length] = '\0';

    int quoted_count = 0;
    char *cursor = input;
    while (*cursor != '\0' && quoted_count < 2) {
        if (*cursor == '"' || *cursor == '\'') {
            char quote = *cursor;
            char *closing_quote = strchr(cursor + 1, quote);
            if (closing_quote == NULL) {
                break;
            }

            char *destination = quoted_count == 0 ? first : second;
            copy_trimmed(destination, cursor + 1, closing_quote);
            ++quoted_count;
            cursor = closing_quote + 1;
        } else {
            ++cursor;
        }
    }

    if (quoted_count < 2) {
        char *first_equals = strchr(input, '=');
        if (first_equals != NULL) {
            char *separator = strpbrk(first_equals + 1, ",\r\n");
            if (separator != NULL) {
                copy_trimmed(first, first_equals + 1, separator);
                char *second_equals = strchr(separator + 1, '=');
                if (second_equals != NULL) {
                    char *end = strpbrk(second_equals + 1, "\r\n");
                    if (end == NULL) {
                        end = input + strlen(input);
                    }
                    copy_trimmed(second, second_equals + 1, end);
                } else {
                    char *next_line = strchr(separator, '\n');
                    if (next_line == NULL) {
                        return 1;
                    }
                    char *end = strchr(next_line + 1, '\n');
                    if (end == NULL) {
                        end = input + strlen(input);
                    }
                    copy_trimmed(second, next_line + 1, end);
                }
            } else {
                char *end = strpbrk(first_equals + 1, "\r\n");
                if (end == NULL) {
                    end = input + strlen(input);
                }
                copy_trimmed(first, first_equals + 1, end);
                return 1;
            }
        } else {
            char *newline = strchr(input, '\n');
            if (newline == NULL) {
                return 1;
            }
            copy_trimmed(first, input, newline);
            char *end = strchr(newline + 1, '\n');
            if (end == NULL) {
                end = input + strlen(input);
            }
            copy_trimmed(second, newline + 1, end);
        }
    }

    int frequencies[256] = {0};
    for (size_t i = 0; first[i] != '\0'; ++i) {
        ++frequencies[(unsigned char)first[i]];
    }
    for (size_t i = 0; second[i] != '\0'; ++i) {
        --frequencies[(unsigned char)second[i]];
    }

    for (int i = 0; i < 256; ++i) {
        if (frequencies[i] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");
    return 0;
}