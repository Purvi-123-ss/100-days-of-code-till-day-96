#include <stdio.h>

struct Student
{
    char name[50];
    int roll;
    int marks;
};

// Function returns structure of top student
struct Student findTopper(struct Student s[])
{
    int i, max = 0;

    for (i = 1; i < 3; i++)
    {
        if (s[i].marks > s[max].marks)
        {
            max = i;
        }
    }

    return s[max];
}

int main()
{
    struct Student s[3], topper;
    int i;

    // Read details of 3 students
    for (i = 0; i < 3; i++)
    {
        scanf("%s %d %d",
              s[i].name, &s[i].roll, &s[i].marks);
    }

    // Get top student from function
    topper = findTopper(s);

    // Print top student's details
    printf("Top Student: %s | Roll: %d | Marks: %d\n",
           topper.name, topper.roll, topper.marks);

    return 0;
}