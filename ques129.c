#include <limits.h>
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("numbers.txt", "r");
    long long value;
    long long sum = 0;
    unsigned long long count = 0;
    int result;

    if (file == NULL) {
        perror("Error opening numbers.txt");
        return 1;
    }

    while ((result = fscanf(file, "%lld", &value)) == 1) {
        if ((value > 0 && sum > LLONG_MAX - value) ||
            (value < 0 && sum < LLONG_MIN - value)) {
            fprintf(stderr, "Error: Sum exceeds the supported range.\n");
            fclose(file);
            return 1;
        }
        if (count == ULLONG_MAX) {
            fprintf(stderr, "Error: Too many integers in numbers.txt.\n");
            fclose(file);
            return 1;
        }

        sum += value;
        count++;
    }

    if (ferror(file)) {
        perror("Error reading numbers.txt");
        fclose(file);
        return 1;
    }
    if (result != EOF) {
        fprintf(stderr, "Error: numbers.txt contains invalid data.\n");
        fclose(file);
        return 1;
    }
    if (fclose(file) == EOF) {
        perror("Error closing numbers.txt");
        return 1;
    }
    if (count == 0) {
        fprintf(stderr, "Error: numbers.txt contains no integers.\n");
        return 1;
    }

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", (double)sum / (double)count);
    return 0;
}