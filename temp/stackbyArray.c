#include <stdio.h>

#define stacksize 100

int stack[stacksize];
int top = -1;

int isFull() {
    if (top == stacksize - 1) {
        return 1;
    }
    return 0;

}

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    return 0;
    
}

void push(int item) {
    if(isFull == 0){
        stack[++top] = item;
    }    
}

int pop() {
    if(isEmpty()){
        return stack[top--];
    }   
}

void stackPrint() {
    printf("[");
    for(int i = 0; i <= top; i++){
        if(i == top) {
            printf("%d", stack[i]);
        }
        else{
            printf("%d,", stack[i]);
        }
    }
    printf("]\n");
}



int main() {
    push(1);
    push(2);
    push(3);
    push(4);

    stackPrint();
    printf("Popped: %d\n",pop());
    printf("Popped: %d\n",pop());
    printf("Popped: %d\n",pop());
    printf("Popped: %d\n",pop());
    printf("Popped: %d\n",pop());
    printf("Popped: %d\n",pop());
    stackPrint();
    return 0;
}
