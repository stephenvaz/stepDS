#include<stdio.h>
#include<stdlib.h>

struct hashItem{
    int value;
    char status;
} *table;

void clear() {
    printf("\033[2J\033[1;1H");
}

void displayTable(int size){
    int i;
    printf("\nIndex\tValue\tStatus");
    for(i=0;i<size;i++){
        printf("\n  %d\t%  d\t",i,table[i].value);
        (table[i].status == '\0') ? printf("  E") : printf("  %c",table[i].status);
    }
}

int hash(int key, int size){
    return key%size%size;
}

void insert(int key, int size){
    int index = hash(key,size);
    if(table[index].status == '\0' || table[index].status == 'D'){
        table[index].value = key;
        table[index].status = 'O';
    }
    else{
        int i, newIndex;
        for(i=0;i<size;i++){
            newIndex = (index+i)%size;
            if(table[newIndex].status == '\0' || table[newIndex].status == 'D'){
                table[newIndex].value = key;
                table[newIndex].status = 'O';
                break;
            }
            
        }
        if(i == size)
            printf("\nTable is full");
    }
}

void search(int key, int size) {
    int index = hash(key, size);
    if(table[index].status == 'O' && table[index].value == key)
        printf("\nElement found at index %d", index);
    else{
        int i, newIndex;
        for(i=0;i<size;i++){
            newIndex = (index+i)%size;
            if(table[newIndex].status == 'O' && table[newIndex].value == key){
                printf("\nIndex %d", newIndex);
                break;
            }
        }
        if(i == size)
            printf("\nNot found");
    }
}

void delete(int key, int size) {
    int index = hash(key, size);
    if(table[index].status == 'O' && table[index].value == key)
        table[index].status = 'D';
    else{
        int i, newIndex;
        for(i=0;i<size;i++){
            newIndex = (index+i)%size;
            if(table[newIndex].status == 'O' && table[newIndex].value == key){
                table[newIndex].status = 'D';
                break;
            }
        }
        if(i == size)
            printf("\nNot found");
    }
}

int main()
{
    printf("Enter the size of the hash table: ");
    int size;
    scanf("%d", &size);
    clear();
    table = (struct hashItem*)malloc(size*sizeof(struct hashItem));
    while(1) {
        printf("1. Search\n2. Insert\n3. Delete\n4. Display\n5. Exit\n:");
        int choice;
        scanf("%d", &choice);
        clear();
        switch(choice) {
            int key;
            case 1:
                printf("\nSearch: ");
                scanf("%d", &key);
                search(key, size);
                break;
            case 2: 
                printf("\nInsert: ");
                scanf("%d", &key);
                insert(key, size);
                break;
            case 3:
                printf("\nDelete: ");

                scanf("%d", &key);
                delete(key, size);
                break;
            case 4: 
                displayTable(size);
                break;
            case 5: 
                return 0;
            default: 
                printf("\nInvalid choice");
        }
        getchar();
        getchar();
        clear();
    }
    return 0;
}