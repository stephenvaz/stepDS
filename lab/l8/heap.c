#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int * arr, int* n, int val) {
    // printf("inserting %d\n", val);
    // printf("n: %d\n", ++*n);

    arr[++*n] = val;
    int i = *n;

    int parent = i/2;
    while (parent > 1 && arr[parent] < arr[i]) {
        swap(&arr[parent], &arr[i]);
        i = parent;

        parent = i/2;
    }
}

void heapify(int* a, int n, int i) {
    int largest = i;
    int l = 2*i;
    int r = l + 1;

    while(l <= n && a[l] > a[largest]) {
        largest = l;
    }
    while(r <= n && a[r] > a[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void increaseKey(int* a, int key, int size) {
    //find the key which should be increased
    
    int flag = 1;
    for(int i = 1; i < size +1; i++) {
        if(a[i] == key) {
            printf("Enter new key: ");
            int newKey;
            scanf("%d", &newKey);
            a[i] = newKey;
            flag = 0;
            int j = i;
            while(j>1 && a[j/2] < a[j]) {
                swap(&a[j/2], &a[j]);
                j = j/2;
            }
            break;
        }   
    }
    if(flag){
        printf("No such key in heap");
    }
}


void decreaseKey(int* a, int key, int size) {
    //find the key which should be decreased
    //decrease the key
    int flag = 1;
    for(int i = 1; i < size +1; i++) {
        if(a[i] == key) {
            printf("Enter new key: ");
            int newKey;
            scanf("%d", &newKey);
            a[i] = newKey;
            flag = 0;
            int j = i;
            heapify(a, size, j);
            break;
        }   
    }
    if(flag){
        printf("No such key in heap");
    }
}



void heapSort(int* a, int size) {
    int n = size;
    for(int i = n; i > 0; i--) {
        swap(&a[1], &a[i]);
        int j = 1;
        heapify(a, i-1, j);
    }
}


int main()
{
    // int arr[] = {70, 50,40,45,35,39,16,10,9,60};
    int heap[MAX] = {0};
    printf("Enter size of heap: ");
    int size;
    scanf("%d", &size);
    int * arr = malloc(sizeof(int) * size);
    printf("Enter elements of heap: \n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int n = 0;
    // int size = sizeof(arr)/sizeof(arr[0]);
    //heap insertion 1by1
    for(int i=0; i< size ; i++) {
        insert(heap, &n, arr[i]);
    }
    //print heap
    for(int i = 1; i < size +1; i++)
        printf("%d ", heap[i]);

    // //increase key
    int key;
    printf("\nEnter element whose key should be increased: \n");
    scanf("%d", &key);
    increaseKey(heap, key, size);
    for(int i = 1; i < size +1; i++)
        printf("%d ", heap[i]);

    // //decreasekey
    // printf("\nEnter element whose key should be decreased: \n");
    // scanf("%d", &key);
    // decreaseKey(heap, key, size);
    // for(int i = 1; i < size +1; i++)
    //     printf("%d ", heap[i]);

    //heapsort
    printf("\nHeap Sort\n");
    heapSort(heap, size);
    for(int i = 1; i < size +1; i++)
        printf("%d ", heap[i]);
    return 0;
}