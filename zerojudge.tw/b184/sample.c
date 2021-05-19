#include <stdio.h>
#include <stdlib.h>
#define PACKAGE_TOTAL 100

typedef struct item
{
    int v; // 體積: 1~100
    int c; // 利潤: 1~60000
} Item;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int package(int **DP, Item *items, int k)
{
    int y, n; // y = 選, n = 不選
    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 1; j < PACKAGE_TOTAL + 1; j++)
        {
            if (items[i - 1].v > j)
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                y = DP[i - 1][j - items[i - 1].v] + items[i - 1].c;
                n = DP[i - 1][j];
                DP[i][j] = max(y, n);
            }
        }
    }
    return DP[k][PACKAGE_TOTAL];
}

int main()
{
    int k;
    while (scanf("%d", &k) != EOF)
    {
        // 宣告k個物品的空間
        Item *items = (Item *)malloc(k * sizeof(Item));

        // 宣告二維的Dynamic Programming表格
        int **DP = (int **)malloc((k + 1) * sizeof(int *));
        for (int i = 0; i < k + 1; i++)
        {
            DP[i] = (int *)malloc((PACKAGE_TOTAL + 1) * sizeof(int));
            for (int j = 0; j < PACKAGE_TOTAL + 1; j++)
            {
                DP[i][j] = 0;
            }
        }

        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &items[i].v, &items[i].c);
        }

        // 解01背包問題
        printf("%d\n", package(DP, items, k));

        // 釋放記憶體空間
        for (int i = 0; i < k; i++)
        {
            free(DP[i]);
        }
        free(DP);
        free(items);
    }
}