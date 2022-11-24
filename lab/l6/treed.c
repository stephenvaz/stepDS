#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *node;

node createNode(char data)
{
    node temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Stack
{
    int capacity;
    int top;
    struct Node **arr;
};

typedef struct Stack *stack;

stack createStack(int size)
{
    stack s = (struct Stack *)malloc(sizeof(struct Stack));
    s->arr = malloc(sizeof(struct Node) * size);
    s->top = -1;
    s->capacity = size;
    return s;
}

void push(stack s, node data)
{
    if (s->top == s->capacity - 1)
    {
        printf("Overflow");
        return;
    }
    s->arr[++s->top] = data;
}

node pop(stack s)
{
    if (s->top == -1)
    {

        return NULL;
    }
    return s->arr[s->top--];
}

node peek(stack s)
{
    return s->arr[s->top];
}

int isEmpty(stack s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

int isOperand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

node buildTree(char *prefix, int len, stack s)
{
    for (int i = len - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isOperator(c))
        {
            node l = pop(s);
            node r = pop(s);
            node newRoot = createNode(c);
            newRoot->left = l;
            newRoot->right = r;
            push(s, newRoot);
        }
        else if (isOperand(c))
        {
            push(s, createNode(c));
        }
    }
    return pop(s);
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

int eval(node root, int values[])
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return values[root->data];
    return evalOp(eval(root->left, values), eval(root->right, values), root->data);
}

void printInorder(node root)
{
    if (root == NULL)
        return;
    // LDR
    printInorder(root->left);
    printf("%c", root->data);
    printInorder(root->right);
}

void printPostorder(node root) {
    if (root == NULL)
        return;
    // LRD
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%c", root->data);
}

int main()
{
    struct Stack *s = createStack(20);
    char *prefix = malloc(50*sizeof(char));
    printf("Prefix expression: ");
    scanf("%[^\n]s", prefix);
    int len = strlen(prefix);
    // passing prefix str, len of str and stack
    node root = buildTree(prefix, len, s);
    printf("Infix: ");
    printInorder(root);
    // printf("\nPostfix: ");
    // printPostorder(root);
    int values[20];
    int val;
    printf("\nInteger values:-\n");
    for (int i = 0; i < len; i++)
    {
        char c = prefix[i];
        if (isOperand(c) && c != ' ')
        {
            printf("%c = ", c);
            scanf("%d", &val);
            values[c] = val;
        }
    }
    printf("\nValue = %d\n", eval(root, values));
    return 0;
}
// ++-+KL*MN*//*^OPWUVTQ