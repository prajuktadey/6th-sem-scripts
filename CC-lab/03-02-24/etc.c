#include <stdio.h>

int main() {
    const int processors = 2;
    const int tasks = 3;
    int executionTimes[processors][tasks];

    printf("Enter execution times for each task on each processor:\n");
    for (int i = 0; i < processors; ++i) {
        for (int j = 0; j < tasks; ++j) {
            printf("Processor %d, Task %d: ", i + 1, j + 1);
            scanf("%d", &executionTimes[i][j]);
        }
    }

    int minTimeForTask[tasks];
    int minTimeForProcessor[processors];

    // find minimum time for each task on the processors
    for (int j = 0; j < tasks; ++j) {
        minTimeForTask[j] = executionTimes[0][j];

        for (int i = 1; i < processors; ++i) {
            if (executionTimes[i][j] < minTimeForTask[j]) {
                minTimeForTask[j] = executionTimes[i][j];
            }
        }
    }

    for (int i = 0; i < processors; ++i) {
        minTimeForProcessor[i] = minTimeForTask[0];

        for (int j = 1; j < tasks; ++j) {
            if (minTimeForTask[j] < minTimeForProcessor[i]) {
                minTimeForProcessor[i] = minTimeForTask[j];
            }
        }
    }

    int overallMinTime = minTimeForProcessor[0];
    for (int i = 1; i < processors; ++i) {
        if (minTimeForProcessor[i] < overallMinTime) {
            overallMinTime = minTimeForProcessor[i];
        }
    }

    printf("Gantt Chart: ")
    for(i = 0; i<=minTimeForProcessor; i++)
    {
        for(j = i; j<)
    }

    printf("\nMinimum time for each processor:\n");
    for (int i = 0; i < processors; ++i) {
        printf("Processor %d: %d\n", i + 1, minTimeForProcessor[i]);
    }
    printf("\nOverall minimum time: %d\n", overallMinTime);

    return 0;
}

