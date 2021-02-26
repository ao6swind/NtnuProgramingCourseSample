#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;        // n = 有幾行, m = 每一行有幾個數字
    int num[20][20]; // 因為題目已經有限制n和m的大小，不怕記憶體爆掉，所以直接用二維陣列
    int i, j;        // 二維陣列的控制變數
    int max;         // 暫存當前最大值為何
    int sum;         // 暫存每行最大值的加總
    int count;       // 計數有sum能夠被多少個max整除

    // 接收第一行
    while (scanf("%d%d", &n, &m) != EOF)
    {
        // 初始化為零，其實可有可無，想想看為什麼可有可無
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                num[i][j] = 0;
            }
        }

        // 開始接收正整數
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &num[i][j]);
            }
        }

        // 初始化總和與計數器
        sum = 0;
        count = 0;
        for (i = 0; i < n; i++)
        {
            max = 0;
            for (j = 0; j < m; j++)
            {
                if (num[i][j] > max)
                {
                    max = num[i][j];
                }
            }
            sum += max;
        }
        printf("%d\n", sum);

        for (i = 0; i < n; i++)
        {
            max = 0;
            for (j = 0; j < m; j++)
            {
                if (num[i][j] > max)
                {
                    max = num[i][j];
                }
            }
            if (sum % max == 0)
            {
                printf("%d ", max);
                count++;
            }
        }
        if (count == 0)
        {
            printf("-1");
        }
        printf("\n");
    }

    return 0;
}
