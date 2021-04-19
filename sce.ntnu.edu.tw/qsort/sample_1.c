#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// <0 : a < b
// =0 : a = b
// >0 : a > b
int compareFun(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
int main()
{
    int numbers[10] = {0};
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = rand() % 100 + 1;
    }
    printf("before sort: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    qsort(numbers, 10, sizeof(int), compareFun);
    printf("after sort: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}