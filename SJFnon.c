#include <stdio.h>

int main() {
    int n, i, j, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], temp_bt[n];
    int t = 0; // current time
    float avgWT = 0, avgTAT = 0;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp_bt[i] = bt[i];
    }

    int done[n];
    for (i = 0; i < n; i++) done[i] = 0;

    printf("\nGantt Chart:\n");

    while (completed < n) {
        int idx = -1;
        int min_bt = 100000;

        // Find process with minimum burst time among arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= t && done[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            printf("| P%d ", idx + 1);
            t += bt[idx];
            ct[idx] = t;
            bt[idx] = 0;
            done[idx] = 1;
            completed++;
        } else {
            t++; // CPU idle
        }
    }
    printf("|\n");

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - temp_bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], temp_bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
