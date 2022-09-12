#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
bool isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
bool isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    //printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MAX;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MAX;
    return queue->array[queue->rear];
}
void smallest(struct Queue* q1,struct Queue* q2,struct Queue* q3){
    //printf("here");
    if(front(q1)<front(q2)){
        if(front(q1)<front(q3)){
            printf("%d ",front(q1));
            dequeue(q1);
        }
        else{
            printf("%d ",front(q3));
            dequeue(q3);
        }
    }
    
    else{
        if(front(q2)<front(q3)){
            printf("%d ",front(q2));
            dequeue(q2);
        }
        else{
            printf("%d ",front(q3));
            dequeue(q3);
        }
    }
    
}
// Driver program to test above functions./
int main()
{
    struct Queue* q1 = createQueue(10);
    struct Queue* q2 = createQueue(10);
    struct Queue* q3 = createQueue(10);

    struct Queue* arr = createQueue(9);
    struct Queue* final = createQueue(9);
    
    int i=0;
    while(i<9){
        int ans;
        scanf("%d",&ans);
        enqueue(arr,ans);
        i++;
    }
    i=0;
    while(i<9){
        int temp = dequeue(arr);
        if(isEmpty(q1)||temp>=rear(q1)){
            enqueue(q1,temp);
        }
        else if(isEmpty(q2)||temp>=rear(q2)){
            enqueue(q2,temp);
        }
        else if(isEmpty(q3)||temp>=rear(q3)){
            enqueue(q3,temp);
        }
        i++;
    }
    i=0;
    while(!isEmpty(q3)){
        printf("%d",dequeue(q3));
    }
    while(i<9){
        smallest(q1,q2,q3);
        i++;
    }
}