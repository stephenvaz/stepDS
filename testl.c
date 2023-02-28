#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintArray(int a[] , int n) //Pointer of 1st element and size
{
    FILE* ptr = NULL;
    ptr = fopen("selection1.csv","a");
    for (int i = 0; i < n; i++)
    {
        fprintf(ptr,"%d\n",a[i]);
    }
    fprintf(ptr,"\n");
    fclose(ptr);
}

// void Merge(int a[],int low,int mid ,int high)
// {
//     int i,j,k, b[100000];

//     i = low ;
//     j = mid+1; 
//     k = low;
//     while(i<= mid && j<= high)
//     {
//         if (a[i]<a[j])
//         {
//             b[k]=a[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             b[k]=a[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         b[k]=a[i];
//         i++;
//         k++;
//     }
//     while (j <= high)
//     {
//         b[k] = a[j];
//         k++;
//         j++;
//     }

//     for (int i = low ; i <= high; i++)
//     {
//         a[i] = b[i];
//     }
// }
void Merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    i = j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }   
}

void mergeSort(int a[],int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;
        mergeSort(a,low,mid); //one part //recursive
        mergeSort(a,mid+1,high); //second part
        Merge(a,low,mid,high);
    }

}

int main()
{
    int x = 100;
    int a[x];
    for (int i = 0 ; i < x; i++ )
    {
        a[i] = rand();
    }
    for (int i = 99; i <= x ; i += 100 )
    {
        mergeSort(a,0,i);
        PrintArray(a,99);
    }
    return 0;
}
