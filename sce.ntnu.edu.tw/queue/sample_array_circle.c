#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 6

char queue[QUEUE_SIZE];
int head = 0;
int tail = 0;

void funcPrintQueue();
void funcEnqueue(char);
char funcDequeue();

int main()
{
    int action, c;
    char word;
    do
    {
        printf("Action: ");
        c = scanf("%d", &action);
        switch (action)
        {
        case 1:
            getchar(); // 清除緩衝區衝的換行符號
            printf("Enqeue: ");
            scanf("%c", &word);
            funcEnqueue(word);
            break;
        case 0:
            printf("Dequeue\n");
            funcDequeue();
            break;
        }
        funcPrintQueue();
    } while (c != EOF);

    return 0;
}

void funcEnqueue(char value)
{
    if ((tail + 1) % QUEUE_SIZE == head)
    {
        printf("Queue is full.\n");
    }
    else
    {
        tail = (tail + 1) % QUEUE_SIZE;
        queue[tail] = value;
    }
}

char funcDequeue()
{
    if (head == tail)
    {
        printf("Queue is empty.");
        return ' ';
    }
    else
    {
        char value = queue[head];
        queue[head] = ' ';
        head = (head + 1) % QUEUE_SIZE;
        return value;
    }
}

void funcPrintQueue()
{
    printf("Queue: ");
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        printf("%c ", queue[i]);
    }
    printf("\n");
}