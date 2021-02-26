#include <stdio.h>

int main()
{
    int year;
    printf("請輸入西元年\n");
    scanf("%d", &year);

    if (year % 400 == 0)
    {
        printf("閏年\n");
    }
    if (year % 4 == 0 && year % 100 != 0)
    {
        printf("閏年\n");
    }
    else
    {
        printf("平年\n");
    }

    /* 
	// 版本二
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		printf("閏年\n");
	}
	else {
		printf("平年\n");
	}
	*/
    return 0;
}