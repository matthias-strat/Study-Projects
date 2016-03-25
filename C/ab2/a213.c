#include <stdio.h>

int main()
{
    int sd, osr, sr, y, t;

    sd = 40;
    osr = 160;
    sr = 1000;

    printf("Jahr StD OStR StR\n");
    for (y = 3; y <= 60; y += 3)
    {
        // 10% osr -> sd
        t = (osr*10)/100;
        sd += t;
        osr -= t;

        // 20% sr -> osr
        t = (sr*20)/100;
        osr += t;
        sr -= t;

        t = (sd*20)/100;
        sd -= t;
        t = (osr*20)/100;
        osr -= t;
        t = (sr*20)/100;
        sr -= t;

        sr += 1200 - (sd + osr + sr);

        printf("%-4d %-3d %-4d %-3d\n", y, sd, osr, sr);
    }
    
    return 0;
}