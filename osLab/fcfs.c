//implement fcfs and rr

#include<stdio.h>

int main() {
	int n, temp;
	printf("No. of processes: ");
	scanf("%d", &n);
	// n = 3;
	int bt[n], wt[n];
	// int bt[] = {5,11,11};
	int wt[n];
	wt[0] = 0;
	for(int i = 0; i < n; i++) {
		printf("Burst Time for P%d: ", i+1);
		scanf("%d", &temp); 
		bt[i] = temp;
	}
	
	printf("Process\t| Burst Time | Waiting time | Turnaround time\n");
	printf("P1\t|\t%d    |\t  %d\t    |\t%d\n", bt[0], wt[0], bt[0]+wt[0]);
	for(int i = 1; i < n; i++) {
		wt[i] = bt[i-1] + wt[i-1];
		printf("P%d\t|\t%d   |\t  %d\t    |\t%d\n", i+1, bt[i], wt[i], bt[i]+wt[i]);	
	}
	int avgW, avgT;
	avgW = avgT = 0;
	for(int i = 0; i < n; i++) {
		avgW += wt[i];
		avgT += bt[i] + wt[i];
	}
	printf("Avg\t|\t     |\t  %d\t    |\t%d\n", avgW/n, avgT/n);
	return 0;
}
