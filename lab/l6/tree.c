#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *newnode(char data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

struct stack
{
    struct node **arr;
    int capacity;
    int top;
};

struct stack *newstack(int size)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->arr = (struct node **)malloc(sizeof(struct node *) * size);
    s->top = -1;
    s->capacity = size;
    return s;
}

void push(struct stack *s, struct node *data)
{
    if (s->top == s->capacity - 1)
    {
        printf("Overflow");
        return;
    }
    s->arr[++s->top] = data;
}

struct node *pop(struct stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->arr[s->top--];
}

struct node *peek(struct stack *s)
{
    return s->arr[s->top];
}

int empty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}

struct node *tree(char *exp, int len, struct stack *s)
{
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = exp[i];
        if (operator(ch))
        {
            struct node *a = pop(s);
            struct node *b = pop(s);
            struct node *root = newnode(ch);
            root->left = a;
            root->right = b;
            push(s, root);
        }
        else
        {
            push(s, newnode(ch));
        }
    }
    return pop(s);
}

int toint(char ch)
{
    int num = ((int)(ch) + 48);
    return num;
}

int eval(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toint(root->data);

    // Evaluate left subtree
    int l_val = eval(root->left);

    // Evaluate right subtree
    int r_val = eval(root->right);

    // Check which operator to apply
    if (&root->data == "+")
        return l_val + r_val;

    if (&root->data == "-")
        return l_val - r_val;

    if (&root->data == "*")
        return l_val * r_val;

    return l_val / r_val;
}

void display(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%c", root->data);
    display(root->right);
}

int main()
{
    struct node *root = NULL;
    struct stack *s = newstack(20);
    char exp[] = "+a*bc";
    int len = sizeof(exp) / sizeof(exp[0]);
    root = tree(exp, len, s);
    display(root);
    int final = eval(root);
    printf("%d", final);
    return 0;
}