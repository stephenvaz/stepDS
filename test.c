#include<stdio.h>

struct queue
{
    int size;
    int f;
    int r;
    int *data;
} *arr;

typedef struct queue *QUEUE;

QUEUE createQueue(int size)
{
    QUEUE q = malloc(sizeof(struct queue));
    q->size = size;
    q->f = -1;
    q->r = -1;
    q->data = (int *)malloc(sizeof(int) * size);
    return q;
}

QUEUE createArray(int size) {
    QUEUE arr = malloc(sizeof(struct queue)*size);
    for(int i = 0; i < size; i++) {
        QUEUE arr[i] = createQueue(5);
        *arr[i]->f =arr[i]->r = -1;

    }
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
        q->data[q->r] = val;
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
        a = q->data[q->f];
    }
    return a;
}


int main()
{
    
    return 0;
}