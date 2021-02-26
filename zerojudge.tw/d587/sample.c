#include <stdio.h>
// d587這一題如果企圖用氣泡排序法
// 宣告a[1000000]，那麼會遇到stack overflow
int main()
{
    int a[3] = {0};
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        a[temp - 1]++;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            printf("%d ", i + 1);
        }
    }
    return 0;
}
