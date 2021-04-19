// 定時Ｋ炸彈
// 此為約瑟夫問題（Josephus Problem）的變形
// https://www.youtube.com/watch?v=uCsD3ZGzMgE&t=585s&ab_channel=Numberphile
#include <stdio.h>
int main()
{
    // N個人
    // 傳遞M次後爆炸
    // 總共跑K次
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    int lucky = 0;
    for (int i = N - K + 1; i <= N; i++)
    {
        lucky = (lucky + M) % i;
    }

    printf("%d", lucky + 1);
    return 0;
}