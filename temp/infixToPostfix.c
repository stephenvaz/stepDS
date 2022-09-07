#include <stdio.h>
#include <stdlib.h>
#define size 256

struct Stack {
    int top;
    int data[size];
};

typedef struct Stack STACK;

STACK* stack_create() {
    STACK* s = malloc(sizeof(STACK));
    s->top = -1;
    return s;
}

void push(STACK *s, int item) {
    if(s-> top == size - 1) {
        printf("Stack Overflow!\n");
    }
    else {
        s->data[++(s->top)] = item;
    }
}

char pop(STACK *s) {
    if(s->top == -1){
        printf("Stack is Empty!\n");
    }
    else {
        return s->data[(s->top)--];
        // printf("%d\n",s->data[(s->top)--]);
    }
    
}

char postfix() {
    STACK *s = stack_create();
    char exp[256];
    printf("Enter the expression: ");
    scanf("%s", exp);
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] >= '0' && exp[i] <= '9') {
            push(s, exp[i]);
        }
        else {
            int op1 = pop(s);
            int op2 = pop(s);
            int res = 0;
            switch(exp[i]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                case '%':
                    res = op1 % op2;
                    break;
            }
            push(s, res);
        }
    }
    return pop(s);
}

int main() {
    STACK* s = stack_create();
    
    return 0;
}