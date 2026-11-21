#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 4095

int main(void)
{
    char input[MAX_LENGTH + 1];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    input[strcspn(input, "\r\n")] = '\0';
    char *text = input;
    char *equals = strchr(input, '=');
    if (equals != NULL) {
        text = equals + 1;
    }

    while (*text != '\0' && isspace((unsigned char)*text)) {
        ++text;
    }

    size_t length = strlen(text);
    if (length > 0 && (*text == '"' || *text == '\'')) {
        char quote = *text++;
        char *closing_quote = strrchr(text, quote);
        if (closing_quote != NULL) {
            *closing_quote = '\0';
        }
        length = strlen(text);
    } else {
        while (length > 0 && isspace((unsigned char)text[length - 1])) {
            text[--length] = '\0';
        }
    }

    int last_seen[256];
    for (int i = 0; i < 256; ++i) {
        last_seen[i] = -1;
    }

    int window_start = 0;
    int max_length = 0;
    for (int i = 0; i < (int)length; ++i) {
        unsigned char ch = (unsigned char)text[i];
        if (last_seen[ch] >= window_start) {
            window_start = last_seen[ch] + 1;
        }
        last_seen[ch] = i;

        int current_length = i - window_start + 1;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }

    printf("%d\n", max_length);
    return 0;
}