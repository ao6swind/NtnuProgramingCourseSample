#include <stdio.h>

int main()
{
    int a, b, step;
    scanf("%d%d%d", &a, &b, &step);
    int i;
    for (i = a; i <= b; i += step)
    {
        printf("%d ", i);
    }
    return 0;
}
