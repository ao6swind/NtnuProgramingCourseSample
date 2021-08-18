#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 全域變數
char operatorStack[10000]; // 運算子堆疊，在中序轉後序時使用
int operatorStackTop = -1; // 堆疊頂端的索引值，當值為-1時代表堆疊為空

int numberStack[10000];  // 算數堆疊，讀後序式時如果讀到數字，或是做完數學運算後的結果都暫存於此
int numberStackTop = -1; // 算數堆疊頂端，當值為-1時代表堆疊為空

// 函式宣告
void infixToPostfix(char[], char[]); // 中序轉後序的函式
void pushOperator(char);
char popOperator();
int priority(char);
int evaluate(char[]);
void pushNumber(int);
int popNumber();

// 主程式
int main()
{
    char infix[10000];   // 使用者輸入的中序式
    char postfix[10000]; // 轉換後的後序式
    while (gets(infix) != NULL)
    {
        infixToPostfix(infix, postfix);
        printf("infix: %s\n", infix);
        printf("postfix: %s\n", postfix);
        printf("%d\n", evaluate(postfix));
    }
    return 0;
}

// 以下開始定義函式
void infixToPostfix(char infix[], char postfix[])
{
    char *token; // 運用strtok函式切字串時將結果暫存於此變數
    int j = 0;   // 組合postfix時要知道字串長度到哪裡
    char symbol; // 取出運算子或運算元的第一個字元，用來判斷是否為數字

    token = strtok(infix, " ");
    while (token != NULL)
    {
        symbol = *token;
        // 如果是數字，則直接輸出
        if (isdigit(symbol))
        {
            strcpy(&postfix[j], token);
            j += strlen(token); // 輸入的數字有可能是十位數字以上，所以要知道存了幾位字元進去
            postfix[j] = ' ';   // 存完後用空白鍵隔開
            j++;                // 因為上一行有加入一個字元，所以索引值要+1
        }
        else
        {
            if (symbol == '(')
            {
                pushOperator('(');
            }
            else if (symbol == ')')
            {
                while (operatorStack[operatorStackTop] != '(')
                {
                    postfix[j] = popOperator();
                    j++;
                    postfix[j] = ' ';
                    j++;
                }
                // 上一動迴圈做完後運算子堆疊頂端仍是左括號
                // 所以要多做一次pop把左括號丟掉
                popOperator();
            }
            else
            {
                if (priority(symbol) > priority(operatorStack[operatorStackTop]))
                {
                    pushOperator(symbol);
                }
                else
                {
                    while (operatorStackTop > -1 && priority(symbol) <= priority(operatorStack[operatorStackTop]))
                    {
                        postfix[j] = popOperator();
                        j++;
                        postfix[j] = ' ';
                        j++;
                    }
                    pushOperator(symbol);
                }
            }
        }

        // 繼續切下一個字串
        token = strtok(NULL, " ");
    }

    // 如果運算子堆疊中還有東西，則不斷地pop出來直到堆疊為空
    while (operatorStackTop != -1)
    {
        postfix[j] = popOperator();
        j++;
        postfix[j] = ' ';
        j++;
    }

    postfix[j] = '\0'; // 最後補上字串結束字元
}

void pushOperator(char operator)
{
    operatorStackTop++;
    operatorStack[operatorStackTop] = operator;
}

char popOperator()
{
    char item = operatorStack[operatorStackTop];
    operatorStackTop--;
    return item;
}

int priority(char symbol)
{
    switch (symbol)
    {
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

int evaluate(char postfix[])
{
    char *token;
    int number1, number2;

    token = strtok(postfix, " ");
    while (token != NULL)
    {
        if (isdigit(*token))
        {
            pushNumber(atoi(token));
        }
        else
        {
            // 如果從後序式讀到運算子，就從運算元堆疊中拿出前兩個來運算
            // 要注意Ｘ數與被Ｘ數在堆疊中的先後順序
            number2 = popNumber();
            number1 = popNumber();
            switch (*token)
            {
            case '+':
                pushNumber(number1 + number2);
                break;
            case '-':
                pushNumber(number1 - number2);
                break;
            case '*':
                pushNumber(number1 * number2);
                break;
            case '/':
                pushNumber(number1 / number2);
                break;
            case '%':
                pushNumber(number1 % number2);
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return numberStack[numberStackTop];
}

void pushNumber(int number)
{
    numberStackTop++;
    numberStack[numberStackTop] = number;
}

int popNumber()
{
    int number = numberStack[numberStackTop];
    numberStackTop--;
    return number;
}