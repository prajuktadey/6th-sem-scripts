#include <stdio.h>

// function to perform Round Robin scheduling
void roundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int remainingTime[n];

    // copy burst times to remainingTime array
    for (int i = 0; i < n; i++)
        remainingTime[i] = bt[i];

    int time = 0;

    while (1) {
        int done = 1; // to check if all the processes are done

        // traverse all processes
        for (int i = 0; i < n; i++) {
            // if the process is not yet completed
            if (remainingTime[i] > 0) {
                done = 0; // there is still a pending process

                // if burst time is less than or equal to the time quantum
                if (remainingTime[i] <= quantum) {
                    time += remainingTime[i];
                    wt[i] = time - bt[i];
                    remainingTime[i] = 0;
                } else {
                    // process exceeds the time quantum
                    time += quantum;
                    remainingTime[i] -= quantum;
                }
            }
        }

        // if all processes are done, break the loop
        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];


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
    int n, quantum;

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

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    roundRobin(processes, n, burstTime, quantum);

    return 0;
}
