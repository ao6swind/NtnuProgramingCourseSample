#include <stdio.h>
#define QUEUE_SIZE 10

int queue[QUEUE_SIZE];
int tail = -1;

void funcPrintQueue();
void funcEnqueue(int);
int funcDequeue();

int main()
{
    int action, n, c;
    do
    {
        printf("Action: ");
        c = scanf("%d", &action);
        switch (action)
        {
        case 1:
            printf("Enqeue: ");
            scanf("%d", &n);
            funcEnqueue(n);
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

void funcEnqueue(int value)
{
    if (tail < QUEUE_SIZE - 1)
    {
        tail++;
        queue[tail] = value;
    }
    else
    {
        printf("Queue is full.\n");
    }
}

int funcDequeue()
{
    if (tail > -1)
    {
        int value = queue[0];
        for (int i = 1; i <= tail; i++)
        {
            queue[i - 1] = queue[i];
        }
        tail--;
        return value;
    }
    else
    {
        printf("Queue is empty.");
        return NULL;
    }
}

void funcPrintQueue()
{
    printf("Queue: ");
    for (int i = 0; i <= tail; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}