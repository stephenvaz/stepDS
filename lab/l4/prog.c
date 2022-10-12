#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * new, *head, *tail, *curr, *temp;

typedef struct node* NODE;

NODE sort(NODE head)
{
    int prev = 0;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        for (curr = temp->next; curr != NULL; curr = curr->next)
        {
            if (curr->data < temp->data)
            {
                prev = curr->data;
                curr->data = temp->data;
                temp->data = prev;
            }
        }
    }
    return head;
}

void traverse(NODE head)
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(NODE *head)
{
    temp = NULL;
    curr = *head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        *head = temp->prev;
    }
    
}

int lengthRecursively(NODE head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + lengthRecursively(head->next);
    }
}

int main()
{

    int val;
    char ch;
    while (1)
    {
        new = (NODE)malloc(sizeof(struct node));
        printf("Enter value to be inserted in linked list: ");
        scanf("%d", &val);
        new->data = val;
        if (head == NULL)
        {
            head = new;
            tail = new;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            new->next = NULL;
            new->prev = temp;
            tail = new;
        }
        printf("Y-continue, N-exit:");
        scanf(" %c", &ch);
        if (ch == 'n' || ch == 'N')
        {
            break;
        }
    }
    printf("Entered DLL:-\n");
    traverse(head);
    printf("Length of DLL: %d\n", lengthRecursively(head));
    printf("Reverse DLL:-\n");
    reverse(&head);
    traverse(head);
    printf("Sorted DLL:-\n");
    head = sort(head);
    traverse(head);
    
    return 0;
}
