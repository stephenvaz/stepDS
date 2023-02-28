#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

struct stack
{
    int top;
    unsigned size;
    int *data;
};

typedef struct stack *stack;
// ABC-/D*E+
stack createStack(unsigned size)
{
    stack s = malloc(sizeof(*s));
    s->top = -1;
    s->size = size;
    s->data = malloc(sizeof(int) * size);
    return s;
}

void push(stack s, int item)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        s->data[++(s->top)] = item;
    }
}

int isEmpty(stack s)
{
    return s->top == -1;
}

int pop(stack s)
{
    if (!isEmpty(s))
        return s->data[(s->top)--];
    else
    {
        printf("Stack Underflow\n");
    }
    // return -1;
}

int peek(stack s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top];
    }
    // return -1;
}

int isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int evalOp(int a, int b, char operator)
{
    if (operator== '^')
        return (int)pow(a, b);
    if (operator== '/')
        return a / b;
    if (operator== '*')
        return a * b;
    if (operator== '+')
        return a + b;
    if (operator== '-')
        return a - b;
    return 0;
}

int posteval(char pref[], int val[]) {
    int i = 0;
    stack s = createStack(20);
    while(pref[i] !='\0'){
        // printf("\npref[%d]: %c\n", i, pref[i]);
        //check if char
        if(isOperand(pref[i])) {
            // printf("\nis operand\n");
            push(s, val[pref[i]]);
            i++;
        }
        else {
            // printf("\nis operator\n");
            push(s,evalOp(pop(s), pop(s),pref[i++]));
        }
    }
    return pop(s);



}


int main()
{
    printf("ENTER Postfix: ");
    // char pref[100];
    char *pref;
    pref = malloc(sizeof(char));
    scanf("%[^\n]s", pref);
    printf("\n%s", pref);
    int values[10];
    int i = 0;
    printf("\n");


    while (pref[i] != '\0')
    {
        if (isOperand(pref[i]))
        {
            printf("%c:", pref[i]);
            scanf("%d", &values[pref[i]]);
            printf("\n");
        }
        i++;
    }
    printf("%d",posteval(pref,values));
    
    return 0;
}