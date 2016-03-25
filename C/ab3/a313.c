#include <stdio.h>

int main()
{
    int a, b, c, d;
    int e;

    printf("Familie geht wenn:\n\n");
    printf("A  B  C  D\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            for (c = 0; c <= 1; c++) {
                for (d = 0; d <= 1; d++) {
                    if ((a || b || c || d) && !(a&&d) && (!b || c) && (!a || !c || !b) && (a || (d != c)))
                        printf("%d  %d  %d  %d\n", a, b, c, d);
                }
            }
        }
    }

    return 0;
}