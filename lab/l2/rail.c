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
        // printf("Enqued element: %d\n", val);
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
    
    int arr[] = {5,8,1,7,4,2,9,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int nQueue = 2;
    QUEUE q0 = createQueue(size);
    QUEUE q1 = createQueue(size);

    for(int i = 1; i <= sizeof(arr)/sizeof(arr[0]); i++){

        if(arr[i-1] == i) {
            printf("%d", arr[i-1]);

        }
        else {
            if(arr[i-1] == q0->arr[q0->f]) {
                printf("%d", dequeue(q0));
                
            }
            else if(arr[i-1] == q1->arr[q1->f]) {
                printf("%d", dequeue(q1));
            }
            // enqueue(q, arr[i-1]);
            else{
                for(int j = 0; j < nQueue; j++) {
                // if(j == 0) {
                //     enqueue(q0, arr[i-1]);
                // }
                // else if(j == 1) {
                //     enqueue(q1, arr[i-1]);
                // }
                // else if(j == 2) {f
                //     enqueue(q2, arr[i-1]);
                // }
                if(!isFull(q0) && arr[q0->r] < arr[i-1]) {
                    enqueue(q0, arr[i-1]);
                }
                else if(!isFull(q1) && arr[q1->r] < arr[i-1]) {
                    enqueue(q1, arr[i-1]);
                }

            }
            }
            
        }
    }

    return 0;
}