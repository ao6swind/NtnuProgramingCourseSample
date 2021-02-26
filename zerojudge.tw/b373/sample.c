#include <stdio.h>

int main()
{
    int n, temp, count, swap;
    int a[10000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    swap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        count = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                count++;
                swap++;
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
        if (count == 0)
        {
            break;
        }
    }

    printf("%d", swap);
    return 0;
}
