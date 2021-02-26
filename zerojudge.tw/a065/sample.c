#include <stdio.h>
#include <stdlib.h>
int main()
{
    char password[7] = {'0'};

    while (scanf("%s", password) != EOF)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%d", abs(password[i] - password[i + 1]));
        }
        printf("\n");
    }

    return 0;
}
