#include <stdio.h>

int main()
{
    int n;
    printf("請輸入班級人數：");
    scanf("%d", &n);
    int a = n / 12;
    int b = n % 12;
    printf("總共需要付%d元\n", a * 50 + b * 5);
    return 0;
}
