#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};

typedef struct node* Node;

void inorder(Node node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(Node node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
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

Node copyTree(Node node)
{
    if (node == NULL)
        return NULL;
    Node temp = (Node) malloc(sizeof(struct node));
    temp->data = node->data;
    temp->left = copyTree(node->left);
    temp->right = copyTree(node->right);
    return temp;
}

int equalTrees(Node node1, Node node2)
{
    if (node1 == NULL && node2 == NULL)
        return 1;
    if (node1 != NULL && node2 != NULL)
    {
        return
        (
            node1->data == node2->data &&
            equalTrees(node1->left, node2->left) &&
            equalTrees(node1->right, node2->right)
        );
    }
    return 0;
}

void printInternalNodes(Node node)
{
    if (node == NULL)
        return ;
    if (node->left != NULL || node->right != NULL)
        printf("%d ", node->data);
    printInternalNodes(node->left);
    printInternalNodes(node->right);
}

void printLeafNodes(Node node)
{
    if (node == NULL)
        return ;
    if (node->left == NULL && node->right == NULL)
        printf("%d ", node->data);
    printLeafNodes(node->left);
    printLeafNodes(node->right);
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
    printf("Internal nodes are: ");
    printInternalNodes(root);
    printf("\nLeaf nodes are: ");
    printLeafNodes(root);
    printf("\n");

    return 0;
}
