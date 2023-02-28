#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *tail, *temp, *new;

void traversal(struct node *root)
{
    struct node *test = malloc(sizeof(struct node));
    test = root;
    while (test != NULL)
    {
        printf("%d ", test->data);
        test = test->next;
    }
}

void swap(int *a, int *b)
{
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *a;
}

void pairswap(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    struct node *temp1 = (struct node *)malloc(sizeof(struct node *));
    temp = head;
    while (temp->next != NULL && temp->next != NULL)
    {
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
}

struct node *createNode(struct node *head, int data)
{
    if (head == NULL)
    {
        temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = malloc(sizeof(struct node));
        temp->next->data = data;
        temp->next->next = NULL;
    }
    return head;
}

int main()
{
    int data, choice;
    // while(choice)
    // {
    //     new = malloc(sizeof(struct node));
    //     printf("\nEnter the value to be inserted in the linked list: ");
    //     scanf("%d",&data);
    //     new->data = data;
    //     if(head == NULL)
    //     {
    //         head = new;
    //         tail = new;
    //     }
    //     else
    //     {
    //         tail = new;
    //         tail->next = NULL;
    //     }

    //     printf("Press\n1-Continue\n0-Exit");
    //     scanf("%d",&choice);
    // }
    head = NULL;
    do
    {
        printf("\nEnter the value to be inserted in the linked list: ");
        scanf("%d", &data);
        head = createNode(head, data);
        printf("Press\n1-Continue\n0-Exit");
        scanf("%d", &choice);
    } while (choice != 0);
    traversal(head);
    pairswap(head);
    traversal(head);
    return 0;
}