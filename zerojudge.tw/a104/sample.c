#include <stdio.h>

int main()
{
    int n, temp;
    while (scanf("%d", &n) != EOF)
    {
        int a[1000];
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
        }
        printf("\n");
    }
    return 0;
}
