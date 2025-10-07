#include <stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int priority;
    int ct;
    int wt;
    int tat;
    int done;
} Process;

int main() {
    int n, i, completed = 0, t = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].done = 0;
    }

    printf("\nGantt Chart:\n");
    while (completed < n) {
        int idx = -1;
        int max_prio = -1;

        // Find highest priority process among arrived and not done
        for (i = 0; i < n; i++) {
            if (p[i].at <= t && !p[i].done) {
                if (p[i].priority > max_prio) {
                    max_prio = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf("| P%d ", p[idx].pid);
            t += p[idx].bt;
            p[idx].ct = t;
            p[idx].done = 1;
            completed++;
        } else {
            t++; // CPU idle
        }
    }
    printf("|\n");

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
