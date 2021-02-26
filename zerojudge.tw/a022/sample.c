#include <stdio.h>

int main()
{
    char text[10000];
    gets(text);
    int i = 0;
    int j = strlen(text) - 1;
    int isYes = 1;
    while (i < j)
    {
        if (text[i] != text[j])
        {
            isYes = 0;
            break;
        }
        i++;
        j--;
    }

    printf((isYes == 1) ? "yes" : "no");

    return 0;
}
