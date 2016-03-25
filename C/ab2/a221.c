#include <stdio.h>

int main()
{
    int j;
    float kapital, p, zkapital;

    printf("Anfangskapital: ");
    scanf("%f", &kapital);
    printf("Zinssatz (%%): ");
    scanf("%f", &p);
    printf("Zielbetrag: ");
    scanf("%f", &zkapital);

    p /= 100.0f;

    for (j = 0; kapital < zkapital; j++)
    {
        kapital *= (1.0f + p);
    }

    printf("Das Zielkaptial in Hoehe von %.2f € ist nach %d Jahren erreicht "
        "(tatsaechlicher Betrag = %.2f)\n", zkapital, j, kapital);

    return 0;
}