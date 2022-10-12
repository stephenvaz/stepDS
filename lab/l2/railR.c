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
int isEmpty(QUEUE q)
{
    if (q->r < q->f)
        return 1;
    else
        return 0;
}
int isFull(QUEUE q)
{

    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("\nThe queue is full ");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("\nEnqueued element: %d",val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("\nThe queue is Empty ");
    }
    else
    {
        // q->f++;
        a = q->arr[q->f++];
    }
    return a;
}
int look(struct queue *q)
{//returns rear of queue
    if (q->r == -1 || q->f > q->r)
    {
        printf("\nqueue empty");
    }
    else
    {
        return q->arr[q->r];
    }
}

int display(struct queue *q)
{//returns front of queue
    if (q->r == -1 || q->f > q->r)
    {
        printf("\nqueue empty");
    }
    else
    {
        return q->arr[q->f];
    }
}

int main()
{
    int val;
    struct queue q, H1, H2, H3;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    H1.size = 10;
    H1.f = H1.r = 0;
    H1.arr = (int *)malloc(q.size * sizeof(int));
    H2.size = 10;
    H2.f = H2.r = 0;
    H2.arr = (int *)malloc(q.size * sizeof(int));
    H3.size = 10;
    H3.f = H3.r = 0;
    H3.arr = (int *)malloc(q.size * sizeof(int));
    for (int i = 1; i < 10; i++)
    {
        printf("\nEnter element number %d:", i);
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // enqueue(&H1, 0);
    // enqueue(&H2, 0);
    // enqueue(&H3, 0);
    int i = 1;
    q.f++;
    while (!(isEmpty(&q)))
    {
        if (i == display(&q))
        {
            //prints if the element is in the correct position
            printf("\n%d", dequeue(&q));
            i++;
        }
        
        else if (!isFull(&H1) && display(&q) > look(&H1))
            enqueue(&H1, dequeue(&q));
        else if (!isFull(&H2) && display(&q) > look(&H2))
            enqueue(&H2, dequeue(&q));
        else if (!isFull(&H3) && display(&q) > look(&H3))
            enqueue(&H3, dequeue(&q));
    }
    // printf("\n i val%d:\n", i);
    H1.f += 1;
    H2.f += 1;
    H3.f += 1;
    while (i < 10)
    {
        if (i == display(&H1))
        {
            printf("\n%d", dequeue(&H1));
            i++;
        }
        else if (i == display(&H2))
        {
            printf("\n%d", dequeue(&H2));
            i++;
        }
        else if (i == display(&H3))
        {
            printf("\n%d", dequeue(&H3));
            i++;
        }
    }
}