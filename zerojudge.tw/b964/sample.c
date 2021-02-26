#include <stdio.h>

int main()
{
    int n, temp;
    int a[20];
    int max = -1, min = 101;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        if (a[i] < 60 && a[i] > max)
        {
            max = a[i];
        }
        if (a[i] >= 60 && a[i] < min)
        {
            min = a[i];
        }
    }
    printf("\n");
    if (max == -1)
    {
        printf("best case\n");
    }
    else
    {
        printf("%d\n", max);
    }

    if (min == 101)
    {
        printf("worst case\n");
    }
    else
    {
        printf("%d\n", min);
    }

    return 0;
}
