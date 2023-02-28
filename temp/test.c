#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int maxHeight(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

struct Node *create(int data)
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = data;
    root->left = root->right = NULL;
    root->height = 1;
    return root;
}

int BalanceFactor(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left) - height(root->right);
    }
}

struct Node *rightRotate(struct Node *root)
{
    struct Node *m = root->left;
    struct Node *p = m->right;
    m->right = root;
    root->left = p;
    root->height = maxHeight(height(root->left), height(root->right)) + 1;
    m->height = maxHeight(height(m->left), height(m->right)) + 1;
    return m;
}

struct Node *LeftRotate(struct Node *root)
{
    struct Node *m = root->right;
    struct Node *p = m->left;
    m->left = root;
    root->right = p;
    root->height = maxHeight(height(root->left), height(root->right)) + 1;
    m->height = maxHeight(height(m->left), height(m->right)) + 1;
    return m;
}

struct Node *insert(struct Node *root, int data)
{
    int bal;
    if (root == NULL)
    {
        return create(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + maxHeight(height(root->left), height(root->right));
    bal = BalanceFactor(root);

    if (bal > 1 && data < root->left->data)
    {
        return LeftRotate(root);
    }
    if (bal < -1 && data > root->right->data)
    {
        return rightRotate(root);
    }
    if (bal > 1 && data > root->left->data)
    {
        root->left = LeftRotate(root->left);
        return rightRotate(root);
    }
    if (bal < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}
void Inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node *root = NULL;

    while (1)
    {
        int c;
        printf("\n1 - Insert \n2 - Done\n");
        printf("enter your choice :");
        scanf("%d", &c);

        if (c == 0)
        {
            break;
        }

        int data;
        printf("enter data to be inserted : ");
        scanf("%d", &data);

        root = insert(root, data);
    }
    printf("\nInorder Traversal:\n");
    Inorder(root);
    printf("\n");
    printf("\nPreorder Traversal:\n");
    Preorder(root);
    printf("\n");
    printf("\nPostorder Traversal:\n");
    Postorder(root);
    return 0;
}