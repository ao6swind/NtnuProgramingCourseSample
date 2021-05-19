#include <stdio.h>

int sum(int);

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", sum(n));
    }

    return 0;
}

int sum(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return n + sum(n - 1);
    }
}