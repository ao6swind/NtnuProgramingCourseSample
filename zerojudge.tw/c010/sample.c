#include <stdio.h>

int main()
{
    int a[10000] = {0};
    int count = 0;
    int number, temp;

    while (scanf("%d", &a[count]) != EOF)
    {
        // 請想想，為什麼只有一層迴圈
        for (int i = count; i > 0; i--)
        {
            if (a[i] < a[i - 1])
            {
                temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }

        if (count % 2 == 0)
        {
            printf("%d\n", a[count / 2]);
        }
        else
        {
            printf("%d\n", (a[count / 2] + a[count / 2 + 1]) / 2);
        }
        count++;
    }

    return 0;
}
