#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int size = 9;

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int fac(int f) {
	if(f < 1)
		return 1;
	return f*fac(f-1);
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void *thread1(int *vargp)
{
    int n = *((int *) vargp);
	printf("Fibbonaci\nn = %d\n", n);
    
    //scanf("%d", &n);
  	printf("RESULT (from thread1): %d\n", fib(n));
	int f0 = 1;
	int f1 = 1;
	printf("1 1 ");
	for (int i = 2; i < n; i++)
	{
		//print fibbonaci serie upto Fn
		printf("%d ", f0+f1);
		int temp = f0;
		f0 = f1;
		f1 = temp + f1;
	}
	printf("\n\n");
	
}

void *thread2(void *vargp) {
	int n = *((int *) vargp);
	printf("Factorial(n = %d) \n", n);
	printf("RESULT (from thread2): %d\n\n", fac(n));
}

void *thread3(void *vargp) {
	printf("Insertion Sort\n");
	int *a = (int *) vargp;
	printf("Unsorted Array(from thread3):");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i < size; i++) {
		int k = i;
		while(k > 0 && a[k] < a[k-1]) {
            swap(&a[k], &a[k-1]);
            k--;
        }
	}
	printf("Sorted Array(from thread3):");

	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	pthread_t thread_id;
	int *n = malloc(sizeof(n));
	*n = 9;
	int *arr = malloc(sizeof(int)**n);
	for (int i = 0; i < *n; i++)
		arr[i] = rand()%100;
    pthread_create(&thread_id, NULL, thread1, (void*) n);
    //pthread_join(thread_id, NULL);
    sleep(2);
    pthread_create(&thread_id, NULL, thread2, (void*) n);
    //pthread_join(thread_id, NULL);
    sleep(2);
    pthread_create(&thread_id, NULL, thread3, (void*) arr);
    //pthread_join(thread_id, NULL);
    sleep(5);
    pthread_exit(NULL);
	return 0;
}

