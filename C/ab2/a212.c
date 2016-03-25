#include <stdio.h>

int main()
{
    float x, y, a, b, tmp;
    int n, i;

    printf("Bucket 1 (liters): ");
    scanf("%f", &x);
    printf("Bucket 2 (liters): ");
    scanf("%f", &y);
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("n: ");
    scanf("%d", &n);

    printf("N   Bucket 1     Bucket 2\n");
    for (i = 1; i <= n; i++)
    {
        // fill bucket 1 (a% from bucket 1 to bucket 2)
        tmp = x*(a/100.f);
        x -= tmp;
        y += tmp;

        // fill bucket 2 (b% from bucket 2 to bucket 1)
        tmp = y*(b/100.f);
        x += tmp;
        y -= tmp;

        printf("%-4d%-13.2f%.2f\n", i, x, y);
    }

    return 0;
}