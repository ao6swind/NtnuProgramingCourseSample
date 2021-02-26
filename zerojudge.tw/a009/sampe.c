#include <stdio.h>

int main()
{
    char text[10000];
    gets(text);
    while (gets(text))
    {
        for (int i = 0; i <= strlen(text) - 1; i++)
        {
            printf("%c", text[i] - 7);
        }
        printf("\n");
    }

    return 0;
}
