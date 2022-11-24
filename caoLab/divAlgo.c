#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void add(int *a1, int *a2)
{
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

int bin2Dec(int *a1)
{
    int val = 0;
    int k = 0;
    for (int i = max_bits - 1; i >= 0; i--)
    {
        val += a1[i] * pow(2, k++);
    }
    return val;
}

void resDiv(int *q, int *m)
{
    // q is dividend
    int *a = (int *)malloc(max_bits * sizeof(int));   // 0
    int *M2s = (int *)malloc(max_bits * sizeof(int)); // m = divisor
    memcpy(M2s, m, max_bits * sizeof(int));
    twosComp(M2s);
    printf("\nM:");
    display(m, max_bits);
    printf("\nM2s: ");
    display(M2s, max_bits);

    printf("\nInitialization: \nA: ");
    display(a, max_bits);
    printf("Q: ");
    display(q, max_bits);
    int *tempA = (int *)malloc(max_bits * sizeof(int));
    memcpy(tempA, a, max_bits * sizeof(int));
    for (int i = 0; i < max_bits - 1; i++)
    {

        printf("\nIteration %d starts\n", i + 1);
        // shift left
        for (int j = 0; j < max_bits - 1; j++)
        {
            a[j] = a[j + 1];
        }
        a[max_bits - 1] = q[1];
        for (int j = 1; j < max_bits - 1; j++)
        {
            q[j] = q[j + 1];
        }
        printf("After Shift: \nA: ");
        display(a, max_bits);
        printf("Q: ");
        display(q, max_bits);
        memcpy(tempA, a, max_bits * sizeof(int));
        // shift left complete

        // a-m
        add(a, M2s);
        printf("After A-M: \nA: ");
        display(a, max_bits);
        if (a[0] == 0)
            q[max_bits - 1] = 1;

        else if (a[0] == 1)
        {
            q[max_bits - 1] = 0;
            memcpy(a, tempA, max_bits * sizeof(int));
        }
        printf("\nIteration %d completed: \nA: ", i + 1);
        display(a, max_bits);
        printf("\nQ:");
        display(q, max_bits);
    }
    printf("\nRemainder:-\nBinary: ");
    display(a, max_bits);
    printf("Decimal: %d\n", bin2Dec(a));
    printf("\nQuotient:-\nBinary: ");
    display(q, max_bits);
    printf("Decimal: %d\n", bin2Dec(q));
}

int main()
{
    printf("Dividend: ");
    int dividend;
    scanf("%d", &dividend);
    printf("Divisor: ");
    int divisor;
    scanf("%d", &divisor);
    int s1 = number(dividend);
    int s2 = number(divisor);
    max_bits = s1 > s2 ? s1 : s2;
    int *a1 = (int *)malloc(max_bits * sizeof(int));
    int *a2 = (int *)malloc(max_bits * sizeof(int));
    binary(dividend, a1);
    binary(divisor, a2);
    printf("\nDividend: ");
    display(a1, max_bits);
    printf("\nDivisor: ");
    display(a2, max_bits);
    // a1 - dividend a2 - divisor
    resDiv(a1, a2);
    return 0;
}