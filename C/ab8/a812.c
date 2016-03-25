#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void crypt(const char* filein, const char* fileout, const char* pwd)
{
    int keylen;
    FILE* fin, *fout;
    int c, t;

    keylen = strlen(pwd);
    fin = fopen(filein, "rb");
    fout = fopen(fileout, "wb");

    for(c = 0;; c++)
    {
        t = getc(fin);
        if (feof(fin)) break;

        t = t ^ (pwd[c % keylen]);

        putc(t, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main()
{
    char filein[256], fileout[256];
    char pwd[128];

    printf("Input file: ");
    scanf("%s", &filein[0]);
    printf("Output file: ");
    scanf("%s", &fileout[0]);
    printf("Password: ");
    scanf("%s", &pwd[0]);

    crypt(filein, fileout, pwd);
}