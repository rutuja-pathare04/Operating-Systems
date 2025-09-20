#include <stdio.h>

#define MAX 100

int main() {
    int i, j, n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: Number of processes exceeds the maximum allowed (%d).\n", MAX);
        return 1;
    }

    int process[MAX], arrivalTime[MAX], burstTime[MAX];
    int startTime[MAX], completionTime[MAX], turnAroundTime[MAX], waitingTime[MAX];
    float totalTAT = 0, totalWT = 0;

    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter Arrival Time and Burst Time of Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    // Sort by arrival time (FCFS)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrivalTime[i] > arrivalTime[j]) {
                // Swap arrival time
                int temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                // Swap burst time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                // Swap process ID
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Calculate times
    for (i = 0; i < n; i++) {
        if (i == 0) {
            startTime[i] = arrivalTime[i];
        } else {
            startTime[i] = (completionTime[i - 1] < arrivalTime[i]) ? arrivalTime[i] : completionTime[i - 1];
        }

        completionTime[i] = startTime[i] + burstTime[i];
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];

        totalTAT += turnAroundTime[i];
        totalWT += waitingTime[i];
    }

    // Output table
    printf("\nProcess\tAT\tBT\tST\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               process[i], arrivalTime[i], burstTime[i],
               startTime[i], completionTime[i],
               turnAroundTime[i], waitingTime[i]);
    }

    printf("\nAverage Turn Around Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);

    // Gantt chart
    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++) {
        printf(" P%d |", process[i]);
    }

    printf("\n0");
    for (i = 0; i < n; i++) {
        printf("   %d", completionTime[i]);
    }

    printf("\n");

    return 0;
}

