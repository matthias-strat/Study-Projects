#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* emptystr()
{
    char* str;
    str = (char*)malloc(sizeof(char));
    *str = 0;
    return str;
}

char* addstr(char* dynstr, const char* str)
{
    int newSize;
    newSize = strlen(dynstr) + strlen(str) + 1;
    dynstr = (char*)realloc(dynstr, newSize);
    strcat(dynstr, str);
    return dynstr;
}

void freestr(char* dynstr)
{
    free(dynstr);
}

int main()
{
    int i;
    char* dynstr;

    dynstr = emptystr();
    for (i = 0; i < 1000; i++)
        dynstr = addstr(dynstr, "123456789\n");

    printf("%s", dynstr);
    freestr(dynstr);
    return 0;
}