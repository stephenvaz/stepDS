#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};
/* Given a binary tree, print its nodes in inorder*/
typedef struct node* Node;

void inorder(Node node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    inorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);
    /* now recur on right child */
    inorder(node->right);
}

void preorder(Node node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left sutree */
    preorder(node->left);

    /* now recur on right subtree */
    preorder(node->right);
}

void postorder(Node node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    postorder(node->left);

    // then recur on right subtree
    postorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

void printlevel(Node node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        printf("%d ", node->data);
    else if (level > 1)
    {
        printlevel(node->left, level-1);
        printlevel(node->right, level-1);
    }
}

Node createNode()
{
    Node temp, root;
    int data, choice;
    temp = (Node) malloc(sizeof(struct node));
    printf("\n0 - Exit\n1 - New Node\n:");
    scanf("%d", &choice);
    if (choice == 0)
    {
        return 0;
    }
    else
    {
        printf("Data:");
        scanf("%d", &data);
        temp->data = data;
        printf("\nLeft child of %d", data);
        temp->left = createNode();
        printf("\nRight child of %d", data);
        temp->right = createNode();
        return temp;
    }
}

int height(Node node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int main()
{
    Node root;
    printf("Tree creation:-\n ");
    root = createNode();

    // Function call
    printf("\nInorder traversal of binary tree is \n");
    inorder(root);
    printf("\nPreorder traversal of binary tree is \n");
    preorder(root);
    printf("\nPostorder traversal of binary tree is \n");
    postorder(root);
    printf("\nLevel order traversal of binary tree is \n");
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printlevel(root, i);
        printf("\n");
    }
    return 0;
}
