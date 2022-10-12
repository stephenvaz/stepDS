#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int size(int n)
{
    return (int) log2(n)+1;
}

void binary(int no, int **arr, int size)
{
    int i = 0;
    arr =  malloc(size * sizeof(int));
    while (no > 0)
    {
        arr[i] = no % 2;
        no = no / 2;
    }
    for(int i = 0; i < size/2; i++)
    {
        int temp = *arr[i];
        arr[i] = arr[size-i+1];
        arr[size-i+1] = temp;
    }
}

int main() {
    int m, q;
    printf("Enter Multiplicand: ");
    scanf("%d", &m);
    printf("Enter Multiplier: ");
    scanf("%d", &q);
    int s1 = size(m);
    int s2 = size(q);
    // printf("s1 = %d, s2 = %d", s1, s2);
    int *arr1 = malloc(s1 * sizeof(int));
    int *arr2 = malloc(s2 * sizeof(int));
    binary(m, &arr1, s1);
    binary(q, &arr2, s2);
    
}