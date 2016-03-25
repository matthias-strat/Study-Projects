#include <stdio.h>

int main()
{
    int n, d;

    printf("Number: ");
    scanf("%d", &n);

    printf("%d = ", n);
    for (d = 2; d <= n;)
    {
        if ((n % d) == 0)
        {
            printf("%d", d);
            n /= d;
            if(n > 1) printf("*");
        }
        else
            d++;
    }
    printf("\n");
    return 0;
}