#include <stdio.h>

int main() {
    int n, tq, i, j, t = 0, done;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rem[n], wt[n], tat[n], ct[n];
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nGantt Chart:\n");

    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= t) {
                done = 0;
                printf("| P%d ", i + 1);
                if (rem[i] > tq) {
                    t += tq;
                    rem[i] -= tq;
                } else {
                    t += rem[i];
                    rem[i] = 0;
                    ct[i] = t;
                }
            }
        }
        if (done) break;
    }
    printf("|\n");

    float avgWT = 0, avgTAT = 0;
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
