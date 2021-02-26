#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numbers[9]; // 使用者輸入的身分證字號
    int check;       // 後三碼檢查碼
    int current;     // 走訪陣列時所取得的數字（從ASCII轉回整數）
    int max_1;       // 最大的數字
    int max_2;       // 第二大的數字
    int i;           // 控制回圈的變數
    while (scanf("%s", numbers) != EOF)
    {
        check = 0;
        current = 0;
        max_1 = 0;
        max_2 = 0;
        for (i = 0; i < 9; i++)
        {
            current = numbers[i] - '0';
            if (current >= max_1)
            {
                max_2 = max_1;
                max_1 = current;
            }
            else
            {
                if (current >= max_2)
                {
                    max_2 = current;
                }
            }
            // 檢查碼的算法有兩種
            // 方法一：在讀字元陣列時順便把檢查碼算出來
            //   1. 用條件判斷式判斷當前的數字是檢查碼的第幾碼
            //   2. 如果是百位數，則檢查碼加上當前數字乘以100
            //   3. 如果是十位數，則檢查碼加上當前數字乘以100
            //   4. 如果是個位數，則檢查碼加上當前數字
            switch (i)
            {
            case 8:
                check += current;
                break;
            case 7:
                check += current * 10;
                break;
            case 6:
                check += current * 100;
            }
        }
        // 方法二：使用atoi函式
        // check = atoi(&numbers[6]);
        if (max_1 * max_1 + max_2 * max_2 == check)
        {
            printf("Good Morning!\n");
        }
        else
        {
            printf("SPY!\n");
        }
    }

    return 0;
}
