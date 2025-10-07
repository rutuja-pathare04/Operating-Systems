#include <stdio.h>

int main() {
    int n, i, j, completed = 0, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    float avgWT = 0, avgTAT = 0;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nGantt Chart:\n");
    int prev = -1;
    while (completed < n) {
        int idx = -1, min_rt = 100000;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            if (prev != idx) printf("| P%d ", idx + 1);
            rt[idx]--;
            t++;
            prev = idx;
            if (rt[idx] == 0) {
                ct[idx] = t;
                completed++;
            }
        } else {
            t++; // CPU idle
            prev = -1;
        }
    }
    printf("|\n");

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
