#include <stdio.h>
// 這裡還有一個小bug
// 試著改成讀Ｎ筆測試資料（提示EOF)
// 然後把bug修掉
int main()
{
    int num;
    scanf("%d", &num);

    while (num % 10 == 0)
    {
        num = num / 10;
    }

    while (num != 0)
    {
        printf("%d", num % 10);
        num = num / 10;
    }
    return 0;
}
