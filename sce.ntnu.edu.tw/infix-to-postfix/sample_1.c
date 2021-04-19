
#include <stdio.h>
#include <string.h>
#define SIZE 100

// 比較優先權
int precedence(char operator)
{
    switch (operator)
    {
        // 左括號基本上不用看，
        // 因為在主程式裡面，左右括號有自己的處理方式
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 2;
        break;
    }
}

void push(char *stack, int *top, char value)
{
    if (*top < SIZE - 1)
    {
        *top = *top + 1;
        stack[*top] = value;
    }
    else
    {
        printf("Stack is full.\n");
    }
}

char pop(char *stack, int *top)
{
    char result = NULL;
    if (*top > -1)
    {
        result = stack[*top];
        *top = *top - 1;
    }
    else
    {
        printf("Stack is empty %d\n", *top);
    }
    return result;
}

int main()
{
    char stack[SIZE];
    int top = -1;

    // 輸入一個前序式
    char infix[SIZE];
    gets(infix);

    char *token;
    token = strtok(infix, " ");
    while (token != NULL)
    {
        switch (*token)
        {
            // 左括號攻擊力最高，永遠都可以push
        case '(':
            push(stack, &top, *token);
            break;
            // 右括號比較特別，是一直pop直到碰到左括號
        case ')':
            while (stack[top] != '(')
            {
                printf("%c ", pop(stack, &top));
            }
            pop(stack, &top);
            break;
            // 運算子直接比攻防大小
        case '+':
        case '-':
        case '*':
        case '/':
            if (precedence(*token) > precedence(stack[top]))
            {
                push(stack, &top, *token);
            }
            else
            {
                while (top > -1 && precedence(*token) >= precedence(stack[top]))
                {
                    printf("%c ", pop(stack, &top));
                }
                push(stack, &top, *token);
            }
            break;
            // 數字就直接輸出
        default:
            printf("%s ", token);
            break;
        }
        token = strtok(NULL, " ");
    }

    // 最後堆疊裡如果還有運算子就依序pop出來
    while (top > -1)
    {
        printf("%c ", pop(stack, &top));
    }
    return 0;
}