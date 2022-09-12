#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

typedef struct queue *QUEUE;

QUEUE createQueue(int size)
{
    QUEUE q = (QUEUE)malloc(sizeof(struct queue));
    q->size = size;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(sizeof(int) * size);
    return q;
}

int isEmpty(QUEUE q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(QUEUE q)
{
    if (q->r - q->f == q->size)
    {
        return 1;
    }
    return 0;
}

void enqueue(QUEUE q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {

        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(QUEUE q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    int ch, temp;
    QUEUE q = createQueue(5);
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n: ");
        scanf("%d", &ch);
        printf("\e[1;1H\e[2J");
        switch (ch)
        {
        case 1:
            printf("Value:");
            scanf("%d", &temp);
            enqueue(q, temp);
            break;
        case 2:
            // temp = dequeue(q);
            if (!isEmpty(q))
            {
                printf("Dequeued element: %d\n", dequeue(q));
            }
            else
            {
                printf("This Queue is empty\n");
            }
            break;
        case 3:
            for (int i = q->f + 1; i <= q->r; i++)
            {
                printf("%d ", q->arr[i]);
            }
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
        getchar();
        scanf("\e[1;1H\e[2J");
        printf("\e[1;1H\e[2J");
    }
    return 0;
}