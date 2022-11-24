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
 
typedef struct Node * node;

node newNode(char data)
{
    node temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

