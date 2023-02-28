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

// int isEmpty(QUEUE q)
// {
//     if (q->r == q->f)
//     {
//         return 1; // if empty
//     }
//     return 0; // if not empty
// }

int isEmpty(QUEUE q)
{
    if (q->f == -1 || q->f > q->r)
    {
        return 1; // if empty
    }
    return 0; // if not empty
}

// int isFull(QUEUE q)
// {
//     if (q->r - q->f == q->size)
//     {
//         return 1; // if full
//     }
//     return 0; // if not full
// }
int isFull(QUEUE q)
{
    if (q->r == q->size - 1)
    {
        return 1; // if full
    }
    return 0; // if not full
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

void display(QUEUE q)
{
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
int sizeofQueue(QUEUE q)
{
    return q->r - q->f;
}

int main()
{
    int arr[] = {5, 8, 1, 7, 4, 2, 9, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    // int nQueue = 2;
    int j = 0;
    QUEUE q0 = createQueue(size);
    QUEUE q1 = createQueue(size);
    QUEUE q2 = createQueue(size);

    // program logic
    for (int i = 1; i <= size; i++)
    {
        // i is the number that should be found from the array repetitively
        //  printf("Test case #%d\n", i);
        if (j >= size)
        {
            break;
        }
        while (1)
        {
            if (arr[j] == i)
            {
                // printf("c1 met ");
                printf("%d\n", arr[j++]);
                break;
            }
            else
            {
                // dequeue element from queue if it matches with i
                //  if (q0->arr[q0->f] == i) {
                //      printf("c2 met ");
                //      printf("%d\n", dequeue(q0));
                //      break;
                //  }
                //  else if (q1->arr[q1->f] == i) {
                //      printf("c2 met ");
                //      printf("%d\n", dequeue(q1));
                //      break;
                //  }
                //  else if (q2->arr[q2->f] == i) {
                //      printf("c2 met ");
                //      printf("%d\n", dequeue(q2));
                //      break;
                //  }
                // enqueue element to queue if it doesn't match with i
                //  else {
                //  printf("c3 met");
                if (q0->arr[q0->r] < arr[j])
                {
                    // printf("c03 met ");
                    enqueue(q0, arr[j++]);
                    // break;
                }
                else if (q1->arr[q1->r] < arr[j])
                {
                    // printf("c13 met ");
                    enqueue(q1, arr[j++]);
                    // break;
                }
                else if (q2->arr[q2->r] < arr[j])
                {
                    // printf("c14 met ");
                    enqueue(q2, arr[j++]);
                    // break;
                }
                // }
            }
        }
    }
    // dequeing
    //  display(q0);
    //  display(q1);
    //  display(q2);

    // printf("%d ", dequeue(q2));
    // printf("%d ", dequeue(q0));
    // printf("%d ", dequeue(q2));
    // printf("%d ", dequeue(q1));
    // printf("%d ", dequeue(q0));
    // printf("%d ", dequeue(q0));
    // printf("%d %d %d ", isEmpty(q0), isEmpty(q1), isEmpty(q2));

    // printf("%d , %d", q1->arr[q1->f+1], q1->arr[q1->r]);
    // printf("%d %d %d \n", sizeofQueue(q0), sizeofQueue(q1), sizeofQueue(q2));
    int t = 7;
    // while (!isEmpty(q0) && !isEmpty(q1) && !isEmpty(q2))
    while (sizeofQueue(q0) + sizeofQueue(q1) + sizeofQueue(q2))
    {
        
    
        //for 0 0 0 terminate, else run always
        // 0 0 0 -> 0
        // all other combinations should be 1
        // isEmpty returns 1 if empty
        // not empty returns 0
        //  printf("c4 met ");
        // printf(
        // "q0: %d, q1: %d, q2: %d\n",
        // isEmpty(q0), isEmpty(q1), isEmpty(q2));
        // printf("size of queues %d %d %d \n", sizeofQueue(q0), sizeofQueue(q1), sizeofQueue(q2));
            if ((q0->arr[q0->f + 1] < q1->arr[q1->f + 1]) && (q0->arr[q0->f + 1] < q2->arr[q2->f + 1]) || isEmpty(q1))
            {
                // printf("c40 met ");
                printf("%d\n", dequeue(q0));
            }
            else if ((q1->arr[q1->f + 1] < q0->arr[q0->f + 1]) && (q1->arr[q1->f + 1] < q2->arr[q2->f + 1]) || isEmpty(q2) )
            {
                // printf("c41 met ");
                printf("%d\n", dequeue(q1));
            }
            else if ((q2->arr[q2->f + 1] < q0->arr[q0->f + 1]) && (q2->arr[q2->f + 1] < q1->arr[q1->f + 1]))
            {
                // printf("c42 met ");
                printf("%d\n", dequeue(q2));
            }
            
        
        // printf("tempT: %d\n", ++tempT);
    }
    // printf(
    //     "q0: %d, q1: %d, q2: %d\n",
    //     isEmpty(q0), isEmpty(q1), isEmpty(q2));

    // display(q0);
    // display(q1);
    // display(q2);
    // ends here
    return 0;
}

/*
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
*/