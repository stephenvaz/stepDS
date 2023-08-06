#include <stdio.h>

int main()
{
	int n, temp;
	printf("No. of processes: ");
	scanf("%d", &n);
	// n = 3;
	int bt[n], wt[n], at[n];
	// int bt[] = {5,9,6};
	// int at[] = {0,3,6};
	// int wt[3] = {0};
	wt[0] = 0;
	for (int i = 0; i < n; i++)
	{
		printf("Burst and Arrival Time for P%d: ", i + 1);
		scanf("%d", &bt[i]);
		scanf("%d", &at[i]);
	}
	double avgW, avgT;
	avgW = avgT = 0.0;
	printf("Process\t| Arrival Time  | Burst Time | Waiting time | Turnaround time\n");
	printf("P1\t|\t%d\t|\t%d    |\t  %d\t    |\t%d\n", at[0], bt[0], wt[0], bt[0] + wt[0]);
	avgW += wt[0];
	avgT += bt[0] + wt[0];
	for (int i = 1; i < n; i++)
	{
		int bith = 0;
		for (int j = 0; j < i; j++)
		{
			bith += bt[j];
		}
		wt[i] = bith - at[i];
		printf("P%d\t|\t%d\t|\t%d    |\t  %d\t    |\t%d\n", i + 1, at[i], bt[i], wt[i], bt[i] + wt[i]);
		avgW += wt[i];
		avgT += bt[i] + wt[i];
	}
	printf("Avg\t|\t\t|\t     |\t  %.2f\t    |\t%.2f\t\n", avgW / n, avgT / n);
	return 0;
}
