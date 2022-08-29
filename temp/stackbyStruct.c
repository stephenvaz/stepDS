#include <stdio.h>
#include <stdlib.h>

// struct stack {
//     int top;
//     int size;
//     int *data;
// };

#define sS 256

struct stack {
    int top;
    int data[sS];
};

typedef struct stack STACK;


STACK *stack_create() {
    struct stack *s = malloc(sizeof(struct stack));
    s->top = -1;
    return s;
};

void push(STACK *s, int item) {
    if(s-> top == sS - 1) {
        printf("Stack Overflow!\n");
    }
    else {
        s->data[++(s->top)] = item;
    }
}

void pop(STACK *s) {
    if(s->top == -1){
        printf("Stack is Empty!\n");
    }
    else {
        printf("%d\n",s->data[(s->top)--]);
    }
    
}

void display(STACK *s) {
    if(s->top == -1) {
        printf("Stack is Empty!\n");
    }
    else {
        for(int i = s->top; i >=0; i--){
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    // printf("%lu\n", sizeof(struct stack));
    // // sizeof(struct stack);
    STACK *s = stack_create();
    // s->top = -1;
    int choice;
    // s = stack_create();
    while(1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n:");
        scanf("%d", &choice);
        printf("\e[1;1H\e[2J");
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed: ");
            int ele;
            scanf("%d", &ele);
            push(s, ele);
            break;
        case 2:
            pop(s);  
            break;   
        case 3:
            display(s);
            break;
        case 4:
            return 0;
        default:
            break;
        }
        // printf("\e[1;1H\e[2J");
    }
    return 0;
}
