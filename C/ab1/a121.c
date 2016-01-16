#include <stdio.h>

int main()
{
    float z1, z2, z3;
    float tmp;

    printf("1. Zahl: ");
    scanf("%f", &z1);
    printf("2. Zahl: ");
    scanf("%f", &z2);
    printf("3. Zahl: ");
    scanf("%f", &z3);

    if (z1 < z2)
    {
        tmp = z1;
        z1 = z2;
        z2 = tmp;
    }
    if (z1 < z3)
    {
        tmp = z1;
        z1 = z3;
        z3 = tmp;
    }
    if (z2 < z3)
    {
        tmp = z2;
        z2 = z3;
        z3 = tmp;
    }

    printf("\n%f\n%f\n%f\n", z1, z2, z3);
    return 0;
}