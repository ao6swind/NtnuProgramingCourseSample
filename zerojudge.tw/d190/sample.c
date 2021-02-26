#include <stdio.h>

int main()
{
    int n, age;
    do
    {
        scanf("%d", &n);
        int a[100] = {0};
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &age);
                a[age]++;
            }
            for (int i = 0; i < 100; i++)
            {
                if (a[i] > 0)
                {
                    for (int j = 0; j < a[i]; j++)
                    {
                        printf("%d ", i);
                    }
                }
            }
            printf("\n");
        }
    } while (n > 0);
    return 0;
}
