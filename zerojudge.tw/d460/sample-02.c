#include <stdio.h>

int main()
{
    int age;
    printf("請輸入年齡");
    scanf("%d", &age);
    switch (age)
    {
    case 0 ... 5:
        printf("0元");
        break;
    case 6 ... 11:
        printf("590元");
        break;
    case 12 ... 17:
        printf("790元");
        break;
    case 18 ... 59:
        printf("890元");
        break;
    default:
        printf("399元");
        break;
    }
    return 0;
}
