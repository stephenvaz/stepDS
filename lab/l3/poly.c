#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val, pow;
    struct Node *next;
} *head, *tail, *temp, *flag;

typedef struct Node *NODE;

NODE createNode(NODE head, int val, int pow)
{
    if (head == NULL)
    {
        temp = (NODE)malloc(sizeof(NODE));
        temp->val = val;
        temp->pow = pow;
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
        temp->next = (NODE)malloc(sizeof(NODE));
        temp->next->val = val;
        temp->next->pow = pow;
        temp->next->next = NULL;
    }
    return head;
}

void display(NODE head)
{
    temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d + ", temp->val, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int val, pow;
    char ch;
    head = NULL;
    do
    {
        printf("Enter the value and power of the term: ");
        scanf("%d %d", &val, &pow);
        head = createNode(head, val, pow);
        printf("Do you want to enter more terms? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');
    display(head);
    return 0;
}