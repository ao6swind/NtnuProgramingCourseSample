#include <stdio.h>
void rotate(int s[][100], int row, int col);
void flip(int s[][100], int row, int col);

int main()
{
    int s[100][100], op[100];
    int i, j, R, C, M, k, temp;

    while (scanf("%d%d%d", &R, &C, &M) != EOF)
    {
        for (i = 0; i < R; i++)
        {
            for (j = 0; j < C; j++)
            {
                scanf("%d", &s[i][j]);
            }
        }
        for (i = 0; i < M; i++)
        {
            scanf("%d", &op[i]);
        }
        for (k = M - 1; k >= 0; k--)
        {
            if (op[k] == 0)
            {
                rotate(s, R, C);
                temp = R;
                R = C;
                C = temp;
            }
            else
            {
                flip(s, R, C);
            }
        }

        printf("%d %d\n", R, C);
        for (i = 0; i < R; i++)
        {
            for (j = 0; j < C - 1; j++)
            {
                printf("%d ", s[i][j]);
            }
            printf("%d\n", s[i][j]);
        }
    }
    return 0;
}
void rotate(int s[][100], int row, int col)
{
    int i, j, temp;
    int t[100][100];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            t[col - j - 1][i] = s[i][j];
        }
    }
    temp = row;
    row = col;
    col = temp;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            s[i][j] = t[i][j];
        }
    }
}

void flip(int s[][100], int row, int col)
{
    int i, j;
    int t[100][100];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            t[row - i - 1][j] = s[i][j];
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            s[i][j] = t[i][j];
        }
    }
}