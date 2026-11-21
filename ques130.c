#include <stdio.h>

int main(void)
{
    FILE *file;
    int studentCount;
    int i;

    printf("Number of students: ");
    if (scanf("%d", &studentCount) != 1 || studentCount <= 0) {
        fprintf(stderr, "Error: Enter a positive number of students.\n");
        return 1;
    }

    file = fopen("students.txt", "w");
    if (file == NULL) {
        perror("Error opening students.txt");
        return 1;
    }

    for (i = 0; i < studentCount; i++) {
        char name[50];
        int roll;
        double marks;

        printf("Student %d (name roll marks): ", i + 1);
        if (scanf("%49s %d %lf", name, &roll, &marks) != 3) {
            fprintf(stderr, "Error: Invalid student record.\n");
            fclose(file);
            return 1;
        }

        if (fprintf(file, "%s %d %g\n", name, roll, marks) < 0) {
            perror("Error writing students.txt");
            fclose(file);
            return 1;
        }
    }

    if (fclose(file) == EOF) {
        perror("Error closing students.txt");
        return 1;
    }

    file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Error reopening students.txt");
        return 1;
    }

    for (i = 0; i < studentCount; i++) {
        char name[50];
        int roll;
        double marks;

        if (fscanf(file, "%49s %d %lf", name, &roll, &marks) != 3) {
            fprintf(stderr, "Error: Could not read a student record.\n");
            fclose(file);
            return 1;
        }

        printf("Name: %s | Roll: %d | Marks: %g\n", name, roll, marks);
    }

    if (fclose(file) == EOF) {
        perror("Error closing students.txt");
        return 1;
    }

    return 0;
}