#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int n, i, j;
    char *token;
    char *words[26] = {".-", "-...", "-.-.", "-..",
                       ".", "..-.", "--.", "....",
                       "..", ".---", "-.-", ".-..",
                       "--", "-.", "---", ".--.",
                       "--.-", ".-.", "...", "-",
                       "..-", "...-", ".--", "-..-",
                       "-.--", "--.."};

    while (scanf("%d", &n) != EOF)
    {
        getchar();
        for (i = 0; i < n; i++)
        {
            gets(input);
            token = strtok(input, " ");
            while (token != NULL)
            {
                for (j = 0; j < 26; j++)
                {
                    if (strcmp(token, words[j]) == 0)
                    {
                        printf("%c", j + 'A');
                    }
                }

                token = strtok(NULL, " ");
            }
            printf("\n");
        }
    }
    return 0;
}