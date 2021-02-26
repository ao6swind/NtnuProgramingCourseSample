#include <stdio.h>

int main()
{
    int m, n, t;
    while (scanf("%d,%d", &m, &n) != EOF)
    {
        t = m % n;
        while (t != 0)
        {
            m = n;
            n = t;
            t = m % n;
        }
        printf("%d\n", n);
    }
    return 0;
}
