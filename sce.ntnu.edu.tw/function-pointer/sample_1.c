#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void printArray(int *, int);

int main()
{
    srand(time(NULL));
    int numbers[SIZE] = {0};
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = rand() % 100;
    }

    int (*funcNickName)(int *, int) = printArray;
    printArray(numbers, SIZE);
    funcNickName(numbers, SIZE);
    return 0;
}

void printArray(int *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}