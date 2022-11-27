#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *next, *prev;
} *head, *tail, *temp;

typedef struct Node *Node;

Node Bubble(Node head)
{
    int swap;
    Node nextnode = malloc(sizeof(struct Node));
    // loop for checking each node with the entire list
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        for (nextnode = temp->next; nextnode->next != NULL; nextnode = nextnode->next)
        {
            if (temp->data > nextnode->data)
            {
                // swapping the nodes
                //  swap = temp->next;
                //  prevnode = temp->prev;
                //  temp->next = nextnode->next;
                //  temp->prev = nextnode->prev;
                //  nextnode->next = swap;
                //  nextnode->prev = prevnode;
                swap = nextnode->data;
                nextnode->data = temp->data;
                temp->data = swap;
            }
        }
    }
    return head;
}

void display(Node head)
{
    Node test = head;
   while(test != NULL)
    {
        printf("%d ", head->data);
        test = test->next;
    }
    // printf("%d ", head->data);
}

int dll_size (Node head)
{
    int count = 0;
    temp = head;
    while(temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// void Bubble(Node head, int size)
// {
//     temp = head;
    
// }

void dllInsert(Node head, int data)
{

    Node new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (head == NULL)
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        new->prev = tail;
        tail = new;
    }
}

void Selection()
{
}

void Insertion()
{
}

void Quick()
{
}

int main()
{
    int choice, value, size;
    head = NULL;
    // char ch = 'y';
    // // Node new, temp, prevnode;
    // printf("Creating a Double Linked List\n");
    // while (ch == 'y')
    // {
    //     new = (Node)malloc(sizeof(Node));
    //     printf("Enter value to be inserted in Double Linked List: ");
    //     scanf("%d", &value);
    //     new->data = value;
    //     if (head == NULL)
    //     {
    //         head = new;
    //         tail = new;
    //         head->next = NULL;
    //         head->prev = NULL;
    //     }
    //     else
    //     {
    //         temp = head;
    //         while (temp->next != NULL)
    //         {
    //             prevnode = temp;
    //             temp = temp->next;
    //         }
    //         temp->next = new;
    //         new->next = NULL;
    //         new->prev = temp;
    //         tail = new;
    //     }
    //     fflush(stdin);
    //     printf("Enter Y- continue, N-exit : ");
    //     scanf(" %c", &ch);
    // }
    // size = dll_size(new);

    printf("Enter in dll:\n");
    while(1)
    {
        printf("Value: ");
        scanf("%d", &value);
        if(value == -1)
            break;
        dllInsert(head, value);
    }

    while (1)
    {
        printf("\n1-Bubble Sort\n2-Selection Sort\n3-Insertion Sort\n4-Quick Sort\n5-Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Display list\n");
            display(head);
            break;
        case 1:
            // Bubble(new,size); 
            
            break;
        case 2: 
            break;
        case 3: 
            break;
        case 4: 
            break;
        case 5: 
            return 0;
        default:
            printf("INVALID OPERATION!");
            break;
        }
    }
    return 0;
}