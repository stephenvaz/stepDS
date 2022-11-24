#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key, height;
    struct Node *l, *r;
};

typedef struct Node *node;

int height(node root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

node newNode(int key)
{
    node node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->l = NULL;
    node->r = NULL;
    node->height = 1;
    return (node);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

node rRotate(node y)
{
    node x = y->l;
    node temp = x->r;
    x->r = y;
    y->l = temp;
    y->height = max(height(y->l), height(y->r)) + 1;
    x->height = max(height(x->l), height(x->r)) + 1;
    return x;
}

node lRotate(node x)
{
    node y = x->r;
    node temp = y->l;
    y->l = x;
    x->r = temp;
    x->height = max(height(x->l), height(x->r)) + 1;
    y->height = max(height(y->l), height(y->r)) + 1;
    return y;
}

int getBalance(node N)
{
    if (N == NULL)
        return 0;
    return height(N->l) - height(N->r);
}

node avlInsert(node node, int key)
{
    if (node == NULL)
    {
        return (newNode(key));
    }
    if (key < node->key)
    {
        node->l = avlInsert(node->l, key);
    }
    else if (key > node->key)
    {
        node->r = avlInsert(node->r, key);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(height(node->l), height(node->r));
    int balance = getBalance(node); //l-r
    if (balance > 1 && key < node->l->key) //if ll
    {
        return rRotate(node);
    }
    if (balance < -1 && key > node->r->key)//if rr
    {
        return lRotate(node);
    }
    if (balance > 1 && key > node->l->key)//if lr
    {
        node->l = lRotate(node->l);
        return rRotate(node);
    }
    if (balance < -1 && key < node->r->key)//if rl
    {
        node->r = rRotate(node->r);
        return lRotate(node);
    }
    return node;
}

void inOrder(node root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->l);
    printf("%d ", root->key);
    inOrder(root->r);
}

void preOrder(node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    preOrder(root->l);
    preOrder(root->r);
}

void postOrder(node root)
{
    if (root == NULL)
        return;
    postOrder(root->l);
    postOrder(root->r);
    printf("%d ", root->key);
}

int main()
{
    node root = NULL;
    while (1)
    {
        int choice;
        printf("1-Insert 0-Exit\n");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        printf("Enter key: ");
        int x;
        scanf("%d", &x);
        root = avlInsert(root, x);
    }
    printf("\nInorder\n");
    inOrder(root);
    printf("\nPreorder\n");
    preOrder(root);
    printf("\nPostorder\n");
    postOrder(root);
    return 0;
}