#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
} *head, *tail, *temp;

typedef struct node * node;

node createNode(node root, int val) {
    if (head == NULL) {
        node temp = malloc(sizeof(*temp));
        temp->data = val;
        temp->next = NULL;
        head = temp;
        tail = temp;
    }
    else {
        temp = root;
        while(temp->next != NULL) 
            temp = temp->next;
        temp->next = malloc(sizeof(struct node));
        temp->next->data = val;
        tail = temp->next;
    }
    return head;
}

void traversal(node root) {
    temp = root;
    while (temp!=NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}

int main()
{
    node head;
    int choice, data = 1;
    do {
        printf("\nData:\n");
        scanf("%d", &data);
        head = createNode(head,data);
        printf("\n1. Cont 0. exit\n");
        scanf("%d", &choice);
    } while (choice != 0);
    traversal(head);
    return 0;
}