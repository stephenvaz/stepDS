#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int max_bits;

int number(int num)
{
    if (ceil(log2(num)) == floor(log2(num)))
        return (int)log2(num) + 1;
    return (int)log2(num) + 2;
}

void twosComp(int *arr)
{
    int i;
    for (i = 0; i < max_bits; i++)
    {
        arr[i] = !arr[i];
    }
    int carry = 1;
    for (i = max_bits - 1; i >= 0; i--)
    {
        if (arr[i] == 1 && carry == 1)
        {
            arr[i] = 0;
            carry = 1;
        }
        else if (arr[i] == 0 && carry == 1)
        {
            arr[i] = 1;
            carry = 0;
        }
    }
}

void binary(int number, int *arr)
{
    int i = 0;
    int flag = 0;
    if (number < 0)
    {
        number = number * -1;
        flag = 1;
    }
    // printf("\nnumber:%d\n", number);
    while (number > 0)
    {
        arr[max_bits - i - 1] = number % 2;
        number = number / 2;
        i++;
    }
    if (flag)
    {
        twosComp(arr);
    }

    // printf("\nSize: %d\n", i);
}

void display(int *arr, int number)
{
    printf("\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

long long bin2Dec(int *a1, int *a2)
{
    long long val = 0;
    int k = 0;
    for (int i = max_bits - 1; i >= 0; i--)
    {
        val += a2[i] * pow(2, k++);
    }
    for (int i = max_bits - 1; i >= 0; i--)
    {
        val += a1[i] * pow(2, k++);
    }
    return val;
}

void add(int *a1, int *a2) {
    int c = 0;
    for (int j = max_bits - 1; j >= 0; j--)
    {
        a1[j] = a1[j] + a2[j] + c;
        if (a1[j] > 1)
        {
            a1[j] = a1[j] % 2;
            c = 1;
        }
        else
        {
            c = 0;
        }
    }
}

void boothsAlgo(int *arr1, int *arr2)
{
    int *A = (int *)malloc(max_bits * sizeof(int));   // A
    int *M2s = (int *)malloc(max_bits * sizeof(int)); // M2s
    memcpy(M2s, arr1, max_bits * sizeof(int));
    twosComp(M2s);
    int q1 = 0;
    // int *q0 = arr2[max_bits-1];

    // Values to be used for algo

    printf("\nInitially\nA: ");
    display(A, max_bits);
    printf("\nM: ");
    display(arr1, max_bits);
    printf("\nM2s: ");
    display(M2s, max_bits);
    printf("\nQ: ");
    display(arr2, max_bits);
    printf("Q0: %d Q-1: %d\n", arr2[max_bits - 1], q1);

    // no idea
    // q = arr2
    int k = 1;
    for (int i = 0; i < max_bits; i++)
    {
        printf("\nIteration: %d\n", k++);
        // a = a - m
        if (arr2[max_bits - 1] == 1 && q1 == 0)
        {
            add(A, M2s);
        }
        else if (arr2[max_bits - 1] == 0 && q1 == 1)
        {
            add(A, arr1);
        }

        // shift right
        q1 = arr2[max_bits - 1];
        for (int j = max_bits - 1; j > 0; j--)
        {
            arr2[j] = arr2[j - 1];
        }
        arr2[0] = A[max_bits - 1];
        for (int j = max_bits - 1; j > 0; j--)
        {
            A[j] = A[j - 1];
        }
        printf("\nA: ");
        display(A, max_bits);
        printf("\nQ: ");
        display(arr2, max_bits);
        printf("Q0: %d Q-1: %d\n", arr2[max_bits - 1], q1);
    }
    printf("\nResult(Binary)\nA: ");
    display(A, max_bits);
    printf("Q: ");
    display(arr2, max_bits);
    printf("Q0: %d Q-1: %d\n", arr2[max_bits - 1], q1);
    printf("\nResult (Decimal): %lld\n", bin2Dec(A, arr2));
}

int main()
{
    int m, q;
    printf("Enter Multiplicand: ");
    scanf("%d", &m);
    printf("Enter Multiplier: ");
    scanf("%d", &q);
    int s1 = number(m);
    int s2 = number(q);
    max_bits = (s1 > s2) ? s1 : s2;
    // printf("s1 = %d, s2 = %d, max = %d", s1, s2, max_bits);
    int *arr1 = malloc(max_bits * sizeof(int));
    int *arr2 = malloc(max_bits * sizeof(int));
    binary(m, arr1);
    binary(q, arr2);
    // display(arr1, max_bits); // Multiplicand M
    // display(arr2, max_bits); // Multiplier Q
    boothsAlgo(arr1, arr2);
}