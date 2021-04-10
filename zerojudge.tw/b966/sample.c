#include <stdio.h>

typedef struct line
{
    int left;
    int right;
} Line;

int main()
{
    int n;                   // 輸入幾組線段
    int i, j;                // 迴圈控制變數
    int total = 0;           // 線段總長度
    int rightMax;            // 當前最右邊的值
    Line lines[10000], temp; // temp 用來做氣泡排序法的暫存變數

    while (scanf("%d", &n) != EOF)
    {
        // 不斷讀入線段
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &lines[i].left, &lines[i].right);
        }

        // 排序
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (lines[j].left > lines[j + 1].left)
                {
                    temp = lines[j];
                    lines[j] = lines[j + 1];
                    lines[j + 1] = temp;
                }
            }
        }

        // 計算線段長度
        for (i = 0; i < n; i++)
        {
            if (i > 0)
            {
                if (lines[i].right > rightMax)
                {
                    if (lines[i].left >= rightMax)
                    {
                        total += lines[i].right - lines[i].left;
                    }
                    else
                    {
                        total += lines[i].right - rightMax;
                    }
                    rightMax = lines[i].right;
                }
            }
            else
            {
                total = lines[i].right - lines[i].left;
                rightMax = lines[i].right;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}