#include <stdio.h>

int main()
{
    int n1, n2;

    printf("First number: ");
    scanf("%d", &n1);
    printf("Second number: ");
    scanf("%d", &n2);

    // find gcd (greatest common divisor)
    for (; n1 != n2; )
    {
        if (n1 > n2) n1 -= n2;
        else n2 -= n1;
    }

    printf("the GCD is: %d\n", n1);
    return 0;
}