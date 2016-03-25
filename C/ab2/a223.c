#include <stdio.h>

int main()
{
    float infectRate, immuneRate;
    int population, healthy, ill, immune, days, i;

    printf("infection rate: ");
    scanf("%f", &infectRate);
    printf("immunization rate: ");
    scanf("%f", &immuneRate);
    printf("population: ");
    scanf("%d", &population);
    printf("ill: ");
    scanf("%d", &ill);
    printf("days: ");
    scanf("%d", &days);

    healthy = population - ill;
    immune = 0;

    printf("day  healthy  ill  immune\n");
    for (i = 0; i <= days; i++)
    {
        if (i > 0)
        {
            healthy = healthy - (infectRate*(healthy*ill/population));
            immune = immune + immuneRate*ill;
            ill = population - healthy - immune;
        }
        printf("%-4d %-8d %-4d %d\n", i, healthy, ill, immune);
    }

    return 0;
}