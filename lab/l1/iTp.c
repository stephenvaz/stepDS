#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    unsigned size;
    char *data;
};

typedef struct stack *STACK;

STACK stack_create(unsigned size)
{
    STACK s = (STACK)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = size;
    s->data = (char *)malloc(sizeof(char) * size);
    return s;
}

void push(STACK s, char item)
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

int isEmpty(STACK s)
{
    return s->top == -1;
}

char pop(STACK s)
{
    if (!isEmpty(s))
        return s->data[(s->top)--];
    else
    {
        printf("Stack Underflow\n");
    }
    return ' ';
}

char peek(STACK s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top];
    }
    return ' ';
}

int isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

void infixToPostfix(char *exp, STACK s)
{
    printf("Postfix Expression: ");
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isOperand(exp[i]))
        {
            printf("%c", exp[i++]);
        }
        else if (exp[i] == '(')
        {
            push(s, exp[i++]);
        }
        else if (exp[i] == ')')
        {
            while (peek(s) != '(')
            {
                printf("%c", pop(s));
            }
            pop(s);
            i++;
        }
        else
        {
            while (precedence(exp[i]) <= precedence(peek(s)))
            {
                printf("%c", pop(s));
            }
            push(s, exp[i++]);
        }
    }
    while (!isEmpty(s))
    {
        printf("%c", pop(s));
    }
    printf("\n");
}

int main()
{
    char exp[50];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);
    int expSize = strlen(exp);
    STACK s = stack_create(expSize);
    infixToPostfix(exp, s);
    return 0;
}