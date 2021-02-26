#include <stdio.h>

int main()
{
    int N, a, b, c, d, e;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if ((b - a) == (d - c))
        {
            e = d + (d - c);
        }
        else
        {
            e = d * (d / c);
        }
        printf("%d %d %d %d %d\n", a, b, c, d, e);
    }
    return 0;
}
