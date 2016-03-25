#include <stdlib.h>
#include <stdio.h>

int main()
{
    // find out the password of the encrypted file "crypt.bin"
    // provided information:
    // language: german
    // key len: 4
    //
    // method to find it out: frequency analysis.
    // https://en.wikipedia.org/wiki/Frequency_analysis

    FILE* fin, *fout;
    long dataSize;
    unsigned char* data;
    int i, j, max;
    int freqs[4][256];
    int key[4];
    char strKey[5];
    
    // Step 1: Load the file into memory
    fin = fopen("crypt.bin", "rb");

    // Figure out file size
    fseek(fin, 0, SEEK_END);
    dataSize = ftell(fin);
    rewind(fin);

    // Read data
    data = (unsigned char*)malloc(dataSize);
    fread(data, dataSize, 1, fin);

    fclose(fin);

    // Step 2: Since we know the key length (< data len), simply apply frequency
    //         analysis to figure out the key and plain text

    // Initialize arrays with 0
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 256; j++)
        {
            freqs[i][j] = 0;
        }
    }
    for (i = 0; i < 4; i++) key[i] = 0;

    // Letter frequencies
    for (i = 0; i < dataSize; i++)
    {
        j = i%4;
        freqs[j][data[i]]++;
        if (freqs[j][data[i]] > freqs[j][key[j]])
            key[j] = data[i];
    }

    // Decode key
    for (i = 0; i < 4; i++)
    {
        // 101 = lowercase e, which is the most frequent letter in german language
        key[i] = key[i] ^ 101;
        strKey[i] = (char)key[i];
    }
    strKey[4] = 0;

    // We've got our key, now decode the data with the key
    for (i = 0; i < dataSize; i++)
    {
        j = i%4;
        data[i] ^= key[j];
    }

    // Save decrypted text to file.
    fout = fopen("crypt_plain.txt", "wb");
    fwrite(data, 1, dataSize, fout);
    fclose(fout);

    printf("key: %s\nplain text: crypt_plain.txt\n", strKey);

    free(data);
    return 0;
}