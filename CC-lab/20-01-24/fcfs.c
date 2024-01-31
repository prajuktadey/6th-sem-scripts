#include <stdio.h>

// function to calculate waiting time and turnaround time
void calculateTimes(int processes[], int n, int bt[], int wt[], int tat[]) {

    // waiting time for the first process is always 0
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void calculateAverages(int wt[], int tat[], int n, float *avg_wt, float *avg_tat) {
    float total_wt = 0, total_tat = 0;

    // calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    *avg_wt = total_wt / n;
    *avg_tat = total_tat / n;
}

void display(int processes[], int bt[], int wt[], int tat[], int n, float avg_wt, float avg_tat) {
    printf("Process\tDuration\tOrder\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], i + 1, 0, wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n\n", avg_tat);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burstTime[n];
    int waitingTime[n];
    int turnaroundTime[n];

    printf("Enter the burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processes[i] = i + 1;
    }

    calculateTimes(processes, n, burstTime, waitingTime, turnaroundTime);
    float avgWaitingTime, avgTurnaroundTime;
    calculateAverages(waitingTime, turnaroundTime, n, &avgWaitingTime, &avgTurnaroundTime);

    display(processes, burstTime, waitingTime, turnaroundTime, n, avgWaitingTime, avgTurnaroundTime);

    return 0;
}
