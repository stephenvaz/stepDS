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
 
struct Node *newNode(char data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
struct Stack
{
    int capacity;
    int top;
    struct Node **arr;
};
 
struct Stack *createStack(int size)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->arr = (struct Node **)malloc(sizeof(struct Node *) * size);
    s->top = -1;
    s->capacity = size;
    return s;
}
 
void push(struct Stack *s, struct Node *data)
{
    if (s->top == s->capacity - 1)
    {
        printf("Overflow");
        return;
    }
    s->arr[++s->top] = data;
}
 
struct Node *pop(struct Stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->arr[s->top--];
}
 
struct Node *peek(struct Stack *s)
{
    return s->arr[s->top];
}
 
int isEmpty(struct Stack *s)
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
    if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
        return 1;
    return 0;
}
 
struct Node *constructTree(char *preorder, int len, struct Stack *s)
{
    for (int i = len - 1; i >= 0; i--)
    {
        char c = preorder[i];
        if (isOperator(c))
        {
            struct Node *a = pop(s);
            struct Node *b = pop(s);
            struct Node *subtree_root = newNode(c);
            subtree_root->left = a;
            subtree_root->right = b;
            push(s, subtree_root);
        }
        else if (isOperand(c))
        {
            push(s, newNode(c));
        }
    }
    return pop(s);
}
 
int operation(long int a, long int b, char operator)
{
    if (operator== '+')
        return a + b;
    if (operator== '-')
        return a - b;
    if (operator== '*')
        return a * b;
    if (operator== '/')
        return a / b;
    if (operator == '^')
        return (int) pow((double)a, (double)b);
}
 
int evalExpTree(struct Node *root, int values[])
{
    if (root == NULL)
        return 0;
 
    if (!root->left && !root->right)
        return values[root->data];
 
    return (operation(evalExpTree(root->left, values), evalExpTree(root->right, values), root->data));
}
 
void printInorder(struct Node *root)
{
    if (root == NULL)
        return;
 
    if (root->data == '+' || root->data == '-')
        printf("(");
    printInorder(root->left);
    printf("%c", root->data);
    printInorder(root->right);
    if (root->data == '+' || root->data == '-')
        printf(")");
}
 
int main()
{
 
    struct Stack *s = createStack(50);
 
    char *preorder;
    preorder = malloc(50);
    printf("Enter prefix expression in alphabets: ");
    scanf("%[^\n]s", preorder);
    int len = strlen(preorder);
 
    int values[123] = {0};
    printf("\nEnter values of following operands\n\n");
    for (int i = 0; i < len; i++)
    {
        char c = preorder[i];
        if (isOperand(c) && c != ' ')
        {
            printf("%c = ", c);
            int value;
            scanf("%d", &value);
            values[c] = value;
        }
    }
 
    struct Node *root = constructTree(preorder, len, s);
    printf("Infix expression is: ");
    printInorder(root);
    printf("\nValue of the given expression is = %d\n", evalExpTree(root, values));
 
    free(preorder);
    free(s);
 
    return 0;
}
