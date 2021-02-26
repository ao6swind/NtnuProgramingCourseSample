#include <stdio.h>

int main()
{
    int h1, m1, h2, m2, d;
    scanf("%d%d%d%d", &h1, &m1, &h2, &m2);
    m1 = h1 * 60 + m1;
    m2 = h2 * 60 + m2;
    if (m2 >= m1)
    {
        d = m2 - m1;
    }
    else
    {
        d = m2 + 1440 - m1;
    }
    printf("%d %d", d / 60, d % 60);

    return 0;
}
