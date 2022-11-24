#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b)
{
    int * temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void maxheap (int a[], int n, int i)
{
    int largest = i;
    int l = 2i;
    int r = 2i+1;
    while(l<=n && a[l]>a[largest])
    {
        largest = l;
    }
    while(r<=n && a[r]>a[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(&a[largest],&a[i]);
        maxheap(a,n,largest);
    }
}

void buildheap (int a[], int n)
{
    for(int i = n/2 ; i > 0 ; i--)
    {
        maxheap(a,n,i);
    }
}

void Delete(int a[],int n)
{
    int i = 1, j = 2, val;
    val = a[1];
    a[1] = a[n];
    while (j < n-1)
    {
        if (a[j+1]>a[j])
        {
            j = j+1;
        }
        if (a[i] < a[j])
        {
            swap(&a[i],&a[j]);
            i = j;
            j = 2*j;
        }
        else
            break;
    }
    printf("\nDeleted element = %d",val);
    a[n] = val;
}

int largest(int a[], int n , int k)
{
    for (int i = 1; i < k; i++)
    {
        Delete(a,(n+1)-i);
        printf("%d",a[i]);
    }
    return a[1];
   
}

int main()
{
   int i, n, k, a[100];
   a[0] = 0;
   printf("\nEnter the no of nodes in the tree: \n");
   scanf("%d",&n);
   for(int i = 1 ; i<= n ; i++)
   {
       printf("\nEnter the %d element of the tree: \n",i);
       scanf("%d",&a[i]);
   }
    printf("\n");
    buildheap(a,n);
     printf("\n");
    for(i=1;i <= n;i++)
    {
      printf("%d ",a[i]);
    }
    for (i=7; i>0; i--)
    {
        Delete(a,i);
    }
    printf("\n");
    for(i=1;i <= n;i++)
    {
      printf("%d ",a[i]);
    }

    printf("\nEnter the kth element : ");
    scanf("%d",&k);
    printf("\n%d largest element of heap is : %d",n,largest(a,n,k));

    return 0;
}