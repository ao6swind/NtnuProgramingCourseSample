#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 1000

int stack[STACK_SIZE];
int top = -1;

void push(int value);
int pop();

int main()
{
    int train[STACK_SIZE];
    int n, m, expect;
    scanf("%d", &n);

    while (n != 0)
    {
        scanf("%d", &m);
        while (m != 0)
        {
            train[0] = m;
            for (int i = 1; i < n; i++)
            {
                scanf("%d", &train[i]);
            }

            expect = n;
            top = -1;

            for (int j = n - 1; j >= 0; j--)
            {
                push(train[j]);
                while (top != -1 && stack[top] == expect)
                {
                    pop();
                    expect--;
                }
            }

            if (top == -1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }

            scanf("%d", &m);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int value = stack[top];
    top--;
    return value;
}