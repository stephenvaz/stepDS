#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if((q->r<q->f)){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r - q->f ==q->size){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
       
        q->r++;
        q->arr[q->r] = val;
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
       
    }
    return a;
}

int front(struct queue *q)
{
    if (isEmpty(q))
    printf("Queue is empty");
    else
    return q->arr[q->f];
}

int rear(struct queue *q)
{
     if (isEmpty(q))
    printf("Queue is empty");
    else
    return q->arr[q->r];
}

void greatest(struct queue* q1,struct queue* q2,struct queue* q3){
    if(rear(q1)>rear(q2)){
        if(rear(q1)>rear(q3)){
            printf("%d ",rear(q1));
            dequeue(q1);
        }
        else{
            printf("%d ",rear(q3));
            dequeue(q3);
        }
    }
   
    else{
        if(rear(q2)>rear(q3)){
            printf("%d ",rear(q2));
            dequeue(q2);
        }
        else{
            printf("%d ",rear(q3));
            dequeue(q3);
        }
    }
   
}

int main(){
    int i=0;
    int val;
    struct queue q,q1,q2,q3;
    q.size=10;
    q.f=q.r=0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    q1.size=10;
    q1.f=q1.r=0;
    q1.arr = (int *)malloc(q.size*sizeof(int));
    q2.size=10;
    q2.f=q2.r=0;
    q2.arr = (int *)malloc(q.size*sizeof(int));
    q3.size=10;
    q3.f=q3.r=0;
    q3.arr = (int *)malloc(q.size*sizeof(int));
    printf("\nEnter %d element \n",(q.size-1));
    for(int i=1;i<10;i++){
       scanf("%d",&val);
       enqueue(&q,val);
    }
   
   q.f++;
    while(!isEmpty(&q))
    {
        if(front(&q)>=1)
           enqueue(&q1,dequeue(&q));
        else if(!isFull(&q1) && front(&q)>rear(&q1))
          enqueue(&q1,dequeue(&q));
        else if(!isFull(&q2) && front(&q)>rear(&q2))
          enqueue(&q2,dequeue(&q));
        else if(!isFull(&q3) && front(&q)>rear(&q3))
          enqueue(&q3,dequeue(&q));
    }
   
    while(i<9)
    {
        greatest(&q1,&q2,&q3);
        i++;
    }
   
}