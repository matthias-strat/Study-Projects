#include <stdio.h>

int main()
{
    int year;

    printf("Jahr: ");
    scanf("%d", &year);

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        printf("Das Jahr %d ist ein Schaltjahr.", year);
    else
        printf("Das Jahr %d ist kein Schaltjahr.", year);

    return 0;
}