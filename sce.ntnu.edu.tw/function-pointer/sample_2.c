#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void sort(int *, int, int (*compare)(int, int));
int ascending(int, int);
int descending(int, int);

int main()
{
    srand(time(NULL));
    int numbers[SIZE] = {0};
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = rand() % 100;
    }

    printf("before sort: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    sort(numbers, SIZE, ascending);
    printf("after sort ascending: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    sort(numbers, SIZE, descending);
    printf("after sort descending: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}

void sort(int *numbers, int size, int (*compare)(int, int))
{
    int temp;
    for (int i = 0, count = 1; i < size - 1 && count > 0; i++)
    {
        count = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (compare(numbers[j], numbers[j + 1]) > 0)
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                count++;
            }
        }
    }
}

int ascending(int a, int b)
{
    return a - b;
}

int descending(int a, int b)
{
    return b - a;
}