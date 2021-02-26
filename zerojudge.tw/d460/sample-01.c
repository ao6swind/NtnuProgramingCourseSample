#include <stdio.h>

int main()
{
    int age;
    printf("請輸入年齡");
    scanf("%d", &age);
    if (age >= 0 && age <= 5)
    {
        printf("0元");
    }
    else if (age >= 6 && age <= 11)
    {
        printf("590元");
    }
    else if (age >= 12 && age <= 17)
    {
        printf("790元");
    }
    else if (age >= 18 && age <= 59)
    {
        printf("890元");
    }
    else
    {
        printf("399元");
    }
    return 0;
}
