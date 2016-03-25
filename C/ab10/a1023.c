#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* readFile(const char* filename)
{
    FILE* f;
    long size;
    char* b;

    f = fopen(filename, "rb");

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);

    b = (char*)malloc(size+1);
    fread(b, size, 1, f);

    b[size] = 0;

    fclose(f);
    return b;
}

char* replaceChars(char* str, char old, char new)
{
    for (;*str; str++)
    {
        if (*str == old) *str = new;
    }
    return str;
}

int main()
{
    char* str = readFile("DreiChinesen.txt");
    printf("%s\n", str);
    replaceChars(str, 'e', 'a');
    replaceChars(str, 'i', 'a');
    replaceChars(str, 'o', 'a');
    replaceChars(str, 'u', 'a');
    printf("%s\n", str);
    replaceChars(str, 'a', 'e');
    printf("%s\n", str);
    replaceChars(str, 'e', 'i');
    printf("%s\n", str);
    replaceChars(str, 'i', 'o');
    printf("%s\n", str);
    replaceChars(str, 'o', 'u');
    printf("%s\n", str);
    free(str);
    return 0;
}