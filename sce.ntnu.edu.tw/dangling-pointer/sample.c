#include <stdio.h>
#include <stdlib.h>
/* 這個範例是用來展示當生命週期較長的指標ptr
 * 指到生命週期較短的變數get函式內的i後，
 * 當get函式執行完成後其他函式操作同樣型態資料後會有什麼結果
 */
int *get();
void test();
int main()
{
    int *ptr = get();
    test();
    printf("%d", *ptr);
    return 0;
}
int *get()
{
    int i = 100;
    return &i;
}
void test()
{
    int var = 250;
}