#include <stdio.h>
#include <stdlib.h>

// node for dll
struct Node
{
    int data;
    struct Node *next, *prev;
} *head, *tail;

typedef struct Node *Node;

// dll operations
void clearScreen() {
    printf("\033[2J\033[1;1H");
}
// create dll
void createDLL()
{
    int data;
    // head = malloc(sizeof(struct Node));
    // tail = malloc(sizeof(struct Node));
    printf("Enter list: \n");
    while (1)
    {
        Node new = malloc(sizeof(struct Node));    
        scanf("%d", &data);
        // head = new;
        new -> data = data;
        if (data == -1)
        {
            break;
        }
        if (head == NULL)
        {
            head = tail = new;
            head->data = data;
            head->next  = NULL;
            head->prev = NULL;

        }
        else
        {
            tail->next = new;
            new->prev = tail;
            tail = new;
            tail->next = NULL;
        }
    }
    clearScreen();
}

void displayList(Node head)
{
    Node temp = malloc(sizeof(struct Node));
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// insertion
Node insert(Node head, int data)
{
    Node temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node test = head;
    while (test->next != NULL)
    {
        test = test->next;
    }
    test->next = temp;
    temp->prev = test;
    return head;
}

// int main()
// {
//     createDLL();
//     displayList(head);

//     return 0;
// }