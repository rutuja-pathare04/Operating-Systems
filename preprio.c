#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

typedef struct {
    int pid;
    int at;
    int bt;
    int priority;
    int rt;
    int ct;
    int tat;
    int wt;
} Process;

int main() {
    int n, i, completed = 0, t = 0, io_wait = 2;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[MAX];
    srand(time(0));

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].rt = p[i].bt;
    }

    printf("\nGantt Chart:\n");
    int prev = -1;

    while (completed < n) {
        int idx = -1, max_prio = -1;
        for (i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt > 0) {
                if (p[i].priority > max_prio) {
                    max_prio = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (prev != idx) printf("| P%d ", p[idx].pid);
            p[idx].rt--;
            t++;
            prev = idx;

            if (p[idx].rt == 0) {
                p[idx].ct = t;
                completed++;

                // Simulate I/O wait for next CPU burst if required
                int next_bt = rand() % 5 + 1; // random 1-5 units
                if (next_bt > 0) {
                    t += io_wait;
                    p[idx].rt = next_bt;
                    p[idx].bt += next_bt; // accumulate total burst
                    completed--; // not completed yet
                }
            }
        } else {
            t++; // CPU idle
            prev = -1;
        }
    }
    printf("|\n");

    float avgWT = 0, avgTAT = 0;
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
