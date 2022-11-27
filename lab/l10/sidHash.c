#include <stdio.h>
#include <stdlib.h>

int hashindex(int key)
{
    return (key % 13) % 13;
}

void insert(int arr[], char status[], int size)
{
    int key, index, i, location;
    printf("\nEnter element to be inserted: ");
    scanf("%d", &key);
    location = hashindex(key);
    for (i = 0; i < size; i++)
    {
        index = (location + i) % size;
        if (arr[index] == 0)
        {
            arr[index] = key;
            status[index] = 'O';
            printf("\nElement %d inserted at %d position", key, index);
            break;
        }
    }
    if (i == size)
    {
        printf("Table is Full!");
    }
}

void delete (int arr[], char status[], int size)
{
    int key, i, location, index, flag = 0;
    printf("\nEnter element to be deleted: ");
    scanf("%d", &key);
    location = hashindex(key);
    for (i = 0; i < size; i++)
    {
        index = (location + i) % size;
        if (arr[index] == key)
        {
            status[index] = 'D';
            flag = 1;
            printf("\nElement %d deleted at %d position (Status set as 'D')", key, index);
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element to be deleted i.e %d is not present in table", key);
    }
}

void search(int arr[], char status[], int size)
{
    int key, i, location, index, flag = 0;
    printf("\nEnter element you want to search: ");
    scanf("%d", &key);
    location = hashindex(key);
    for (i = 0; i < size; i++)
    {
        index = (location + i) % size;
        if (arr[index] == key && status[index] != 'D')
        {
            flag = 1;
            printf("\nElement Found! %d is at %d position", key, index);
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element %d is not present in table", key);
    }
}

void display(int arr[], char status[], int size)
{
    printf("\n");
    printf("\n");
    printf("Index\t|\tStatus\t|\tValue");
    printf("\n");
    printf("\t|\t\t|");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t|\t%c\t|\t%d", i, status[i], arr[i]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int size, choice, location, key, i = 0;
    printf("\nEnter the size of the hashing table: ");
    scanf("%d", &size);
    int item[size];
    char status[size];
    for (i = 0; i < size; i++)
    {
        item[i] = 0;
        status[i] = 'E';
    }
    while (1)
    {
        printf("\n1- Insert\n2- Delete\n3- Search\n4- Display\n5- Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(item, status, size);
            break;
        case 2:
            delete(item, status, size);
            break;
        case 3:
            search(item, status, size);
            break;
        case 4:
            display(item, status, size);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid Operation!");
            break;
        }
    }
    return 0;
}