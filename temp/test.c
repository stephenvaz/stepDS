#include <stdio.h>

void insert(int a[],int n,int val)
{
    //n=n+1;
    int parent,temp,i;
    a[n]=val;
    i=n;
    while(i>1)
    {
        parent=i/2;
        if(a[parent]<a[i])
        {
            temp=a[parent];
            a[parent]=a[i];
            a[i]=temp;
            i=parent;
        }
        else
          return;
    }
}

void printArray(int arr[], int n) 
{

  for (int i =1; i < n; i++)

    printf("%d ", arr[i]);

  printf("\n");

}

void inKey(int a[],int pos,int val)
{
    int i,temp;
    if(val<a[pos])
    {
        return;
    }
    else
    {
        a[pos]=val;
        while(pos>1 && a[pos/2] < a[pos])
        {
            temp=a[pos/2];
            a[pos/2]=a[pos];
            a[pos]=temp;
            pos=pos/2;
        }
    }
}

int main()
{
    printf("Hello World");
    int a[50],i=1,choice,len,pos,val;
    do
    {
        printf("enter the value of element::");
        scanf("%d",&a[i]);
        insert(a,i,a[i]);
        printf("\ndo you want to continu press 1 \n press 0 to continue");
        scanf("%d",&choice);
        i++;
       
        // {70, 50,40,45,35,39,16,10,9,60};
    }while(choice!=0);
    
    len=i;
    printf("array printed from heap::");
    printArray(a,len);
    //array printed from heap::70 60 40 45 50 39 16 10 9 35 
    printf("\ndo you want to increase any value of element, enter its position and val:\n");
    scanf("%d %d ",&pos,&val);
    inKey(a,pos,val);
    //array printed after increasing from heap::90 60 70 45 50 39 16 10 9 35 
    printf("array printed after increasing from heap::");
    printArray(a,len);
    
    return 0;
}