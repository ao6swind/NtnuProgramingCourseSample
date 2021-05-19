#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int **array = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            array[i][j] = (i + 1) * (j + 1);
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);
    return 0;
}