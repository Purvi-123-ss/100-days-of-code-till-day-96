#include <stdio.h>

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main(void)
{
    const char *dayNames[] = {
        "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY",
        "THURSDAY", "FRIDAY", "SATURDAY"
    };
    enum Day day;

    for (day = SUNDAY; day <= SATURDAY; day++) {
        printf("%s = %d\n", dayNames[day], day);
    }

    return 0;
}