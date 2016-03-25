#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numbers[100000];

void createFile(char* filename, int len)
{
    int tmp;
    FILE* f;

    // Generate numbers and save them to file
    f = fopen(filename, "w");
    for (; len > 0; len--)
    {
        tmp = rand();
        fprintf(f, "%d\n", tmp);
    }
    fclose(f);
}

int readFile(char* filename, int* nums)
{
    int num, tmp, i;
    FILE* f;

    // Read in the numbers
    f = fopen(filename, "r");
    for (i = 0; fscanf(f, "%d", &tmp) != EOF; i++)
    {
        nums[i] = tmp;
    }

    return i;
}

void sortNumbers(int* nums, int len)
{

}

void writeFile(char* filename, int* nums, int len)
{

}

void validateFile(char* filename)
{

}

int main()
{
    int num, tmp, i;
    FILE* file;

    // Seed random generator with current time
    srand(time(0));

    printf("Num: ");
    scanf("%d", &num);

    if (num > 100000) num = 100000;

    createFile("numbers.txt", num);
    num = readFile("numbers.txt", numbers);
    printf("%d\n", num);
    sortNumbers(numbers, num);
    writeFile("sorted.txt", numbers, num);
    validateFile("sorted.txt");

    return 0;
}