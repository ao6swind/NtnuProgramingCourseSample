#include <stdio.h>
int main()
{
    // 使用者輸入
    int number;
    // 迴圈控制變數
    int i = 0;
    // 存放結果，因為int共計32位元，所以只要32格就好
    int bits[32] = {0};

    printf("請輸入一個數字，我將幫你轉換成2進制");
    scanf("%d", &number);

    do
    {
        bits[i] = number % 2;
        number = number / 2;
        i++;
    } while (number != 0);

    printf("總共 %d bits\n", i);
    printf("結果：");

    // 從最高位元開始printf出來
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", bits[j]);
    }

    return 0;
}
