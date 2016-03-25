#include <stdio.h>

int main()
{   
    int a, b, c;
    int l, r, ok;

    ok = 1;
    printf("associative law\n");
    printf("A  B  C | left right\n");
    printf("--------|-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            for (c = 0; c <= 1; c++) {
                l = a && (b && c);
                r = (a && b) && c;
                if (l != r) ok = 0;
                printf("%d  %d  %d | %-4d %d\n", a, b, c, l, r);
            }
        }
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");

    ok = 1;
    printf("commutative law\n");
    printf("A  B | left right\n");
    printf("-----|-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            l = a && b;
            r = b && a;

            if (l != r) ok = 0;
            printf("%d  %d | %-4d %d\n", a, b, l, r);
        }
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");

    ok = 1;
    printf("merger law\n");
    printf("A  B | left right\n");
    printf("-----|-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            l = (a || b) && a;
            r = a;

            if (l != r) ok = 0;
            printf("%d  %d | %-4d %d\n", a, b, l, r);
        }
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");

    ok = 1;
    printf("distributive law\n");
    printf("A  B  C | left right\n");
    printf("--------|-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            for (c = 0; c <= 1; c++) {
                l = a && (b || c);
                r = (a && b) || (a && c);
                if (l != r) ok = 0;
                printf("%d  %d  %d | %-4d %d\n", a, b, c, l, r);
            }
        }
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");

    ok = 1;
    printf("complementary law\n");
    printf("A  B | left right\n");
    printf("-----|-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            l = a && (b || !b);
            r = a;

            if (l != r) ok = 0;
            printf("%d  %d | %-4d %d\n", a, b, l, r);
        }
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");

    ok = 1;
    printf("idempotency law\n");
    printf("A | left right\n");
    printf("--|-----------\n");
    for (a = 0; a <= 1; a++) {
        l = a && a;
        r = a;

        if (l != r) ok = 0;
        printf("%d | %-4d %d\n", a, l, r);
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");

    ok = 1;
    printf("de morgan's law\n");
    printf("A  B | left right\n");
    printf("-----|-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            l = !(a && b);
            r = !a || !b;

            if (l != r) ok = 0;
            printf("%d  %d | %-4d %d\n", a, b, l, r);
        }
    }
    if (ok) printf(" => ok!\n\n");
    else printf(" => not ok!\n\n");


    return 0;
}