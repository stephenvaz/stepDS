#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void fifo(int *a, int n, int f)
{
    int *pgArr = malloc(f * sizeof(int));
    int pgIndex = 0;
    int pgHit = 0;
    int pgMiss = 1;
    for (int i = 0; i < f; i++)
        pgArr[i] = a[i];

    //print seq
    printf("Page sequence: ");
    printArray(a, n);

    // print page arr
    printf("Page Array: ");
    printArray(pgArr, f);

    // page hit logic
    for (int i = f; i < n; i++)
    {
        printf("\nElement %d\n", a[i]);
        // traverse page array
        for (int j = 0; j < f; j++)
        {
            if (a[i] == pgArr[j])
            {
                printf("Page Hit\n");
                pgMiss = 0;
                pgHit++;
                break;
            }
        }
        // if element not found in page array
        if (pgMiss)
        {
            // replace page array element(fifo)
            printf("Page Miss\n");
            pgArr[pgIndex] = a[i];
            pgIndex = (pgIndex + 1) % f;
        }
        pgMiss = 1;
        // print page array
        printArray(pgArr, f);
    }
    free(pgArr);
    printf("\nPage Hit: %d\n", pgHit);
    printf("Page Hit ratio: %.2f\n", (float)pgHit / n);    
}

void lru(int *a, int n, int f)
{
    int *pgArr = malloc(f * sizeof(int));
    int pgIndex = 0;
    int pgHit = 0;
    int pgMiss = 1;

    //tracks usage of page array elements
    int * temp = malloc(sizeof(int)*f);
    // for(int i=0;i<f;i++)
    //     temp[i]=-1;
    //entereing first f elements
    for (int i = 0; i < f; i++)
        pgArr[i] = a[i];
    printf("Page Array: ");
    printArray(pgArr, f);
    //lru
    for(int i = f; i < n; i++) {
        printf("\nElement %d\n", a[i]);
        // traverse page array
        for (int j = 0; j < f; j++)
        {
            if (a[i] == pgArr[j])
            {
                printf("Page Hit\n");
                pgMiss = 0;
                pgHit++;
                temp[j] += 1;
                break;
            }
        }
        //page miss lru
        if (pgMiss)
        {
            printf("Page Miss\n");
            // //find least used element 
            // int min = temp[0];
            // for(int j = 0; j < f; j++) {
            //     if(temp[j] < min) {
            //         min = temp[j];
            //         pgIndex = j;//stores min index
            //     }
            // }
            // pgArr[pgIndex] = a[i];
            // temp[pgIndex] = 1;
            // pgIndex = 0;
            //lru page miss algo
            int min = INT_MAX;
            int minIndex = 0;
            for(int j = 0; j < f; j++) {
                if(temp[j] < min) {
                    min = temp[j];
                    minIndex = j;
                }
            }
            pgArr[minIndex] = a[i];
            temp[minIndex] = 0;

        }
        pgMiss = 1;
        // pgIndex = 0;
        // print page array
        printArray(pgArr, f);
        printArray(temp, f);
    }
    free(pgArr);
    free(temp);
    printf("\nPage Hit: %d\n", pgHit);
    printf("Page Hit ratio: %.2f\n", (float)pgHit / n);
}

int main()
{
    // int arr[] = {6, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1}; //10,12
    // // int arr[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2}; // 4, 4
    // // int arr[] = {0, 1, 2, 3, 0, 1, 4, 0, 1, 2, 3, 4}; // 3,2
    int n = sizeof(arr) / sizeof(arr[0]);
    int f = 4;

    // // UserInput
    // printf("Number of frames: ");
    // int n;
    // scanf("%d", &n);
    // printf("Enter the number of pages: ");
    // int f;
    // scanf("%d", &f);
    // int *arr = malloc(n * sizeof(int));
    // printf("Enter the pages:\n");
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &arr[i]);


    printf("FIFO\n");
    fifo(arr, n, f);
    printf("\nLRU\n");
    lru(arr, n, f);
    // free(arr);
    return 0;
}
