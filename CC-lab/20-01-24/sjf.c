#include <stdio.h>

// function to perform Shortest Job First (SJF) scheduling
void sjf(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = bt[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (bt[j] > bt[i]) {
                // swap burst times
                int temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;

                // swap process numbers
                temp = processes[j];
                processes[j] = processes[i];
                processes[i] = temp;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
    }

    printf("Process\tDuration\tOrder\tArrival Time\tWaiting Time\tTurnaround Time\n");

    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], i + 1, 0, wt[i], tat[i]);
        totalWaitingTime += wt[i];
        totalTurnaroundTime += tat[i];
    }

    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burstTime[n];

    printf("Enter the burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processes[i] = i + 1;
    }
    sjf(processes, n, burstTime);

    return 0;
}
