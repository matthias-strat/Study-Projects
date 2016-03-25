#include <stdio.h>

int main()
{
    int e;
    int a, b, c, d;

    printf("A  B  C  D | 1  2  3  4\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            for (c = 0; c <= 1; c++) {
                for (d = 0; d <= 1; d++) {
                    printf("%d  %d  %d  %d | ", a, b, c, d);

                    // 1.
                    e = !(a && b) || (c || d);
                    printf("%d  ", e);

                    // 2.
                    e = !(!(a && b) || c) && d;
                    printf("%d  ", e);

                    // 3.
                    e = (!a || b) || (c || !d);
                    printf("%d  ", e);

                    // 4.
                    e = (a || !b) && !((a || c) && d);
                    printf("%d\n", e);
                }
            }
        }
    }

    return 0;
}