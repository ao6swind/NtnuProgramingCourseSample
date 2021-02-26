#include <stdio.h>

int main()
{
    int a[30001]; // 請想想，這裡為什麼要將大小設為30001

    int n, i; // 使用者要輸入幾個整數(1~10000)
    int number;
    int max_frq;

    while (scanf("%d", &n) != EOF)
    {
        // a[30001] = { 0 } 這種初始化方法只能在宣告時
        for (i = 0; i < 30001; i++)
        {
            a[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            scanf("%d", &number);
            a[number]++;
        }

        max_frq = a[1]; // 先把1當作出現次數最多的數字，暫存出現次數
        for (i = 2; i < 30001; i++)
        {
            // 如果當前數字的出現次數更多，則暫存此數字的出現次數
            if (a[i] > max_frq)
            {
                max_frq = a[i];
            }
        }

        for (i = 1; i < 30001; i++)
        {
            if (a[i] == max_frq)
            {
                printf("%d %d\n", i, a[i]);
            }
        }
    }

    return 0;
}
