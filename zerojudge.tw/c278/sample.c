#include <stdio.h>

int main()
{
    int a[100000] = {0};
    int n;     // n 個數字
    int c = 0; // 現在輸入多少數字
    int t = 0; // 兩兩相減後的加總
    int i, j;  // for 迴圈的控制變數
    int temp;

    scanf("%d", &n);
    while (c != n)
    {
        scanf("%d", &a[c]);
        c++;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i += 2)
    {
        t += a[i + 1] - a[i];
    }

    printf("%d", t);

    return 0;
}
