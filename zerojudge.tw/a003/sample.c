#include <stdio.h>

int main()
{
    int M, D, S;
    scanf("%d %d", &M, &D);
    S = (M * 2 + D) % 3;

    switch (S)
    {
    case 0:
        printf("普通\n");
        break;
    case 1:
        printf("吉\n");
        break;
    case 2:
        printf("大吉\n");
        break;
    }
    return 0;
}
