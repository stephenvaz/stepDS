#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *node;

node createNode(int val)
{
    node root = (node)malloc(sizeof(struct node *));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void preorder(node root)
{
    printf("insider preorder");
    if (root == NULL)
    {
        return;
    }
    // DLR
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

int height(node root) {
    if (root == NULL) {
        return -1;
    }
    int l = height(root->left);
    int r = height(root->right);
    return (l>r? l:r);
}
//find node
int main()
{

    node root = createNode(10);
    // printf("\n%d\n", root->data);
    root->left = createNode(20);
    // printf("\n%d\n", root->left->data);
    root->right = createNode(30);
    // printf("\n%d\n", root->right->data);
    root->left->left = createNode(40);
    root->right->right = createNode(50);
    preorder(root);
    printf("%d", height);
    return 0;
}