#include <stdio.h>

int main()
{
    int n;
    printf("請輸入介於1~100之間的整數：");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
