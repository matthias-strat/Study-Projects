#include <stdio.h>

int main()
{
    int num;
    int max, min, i, z;

    printf("Anzahl: ");
    scanf("%d", &num);
    printf("\n");

    for (i = 1; i <= num; i++)
    {
        printf("%d. Zahl: ", i);
        scanf("%d", &z);
        if (i == 1)
            min = max = z;
        else
        {
            if (z < min) min = z;
            if (z > max) max = z;
        }
    }

    printf("\nMinimum: %d\nMaximum: %d\n", min, max);
    return 0;
}