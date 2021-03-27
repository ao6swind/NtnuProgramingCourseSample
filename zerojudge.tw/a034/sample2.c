#include <stdio.h>
// 這裡有溢位的問題需要需要調整
int main()
{
    // 十進制整數，由使用者輸入
    long long int decimal;

    // 二進制，答案
    long long int binary = 0;
    int i = 1;
    printf("請輸入一個數字，我將幫你轉換成2進制:");
    scanf("%lld", &decimal);

    while (decimal != 0)
    {
        binary += (decimal % 2) * i;
        decimal = decimal / 2;
        i *= 10;
    }
    printf("%lld\n", binary);
    return 0;
}