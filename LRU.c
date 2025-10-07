#include <stdio.h>

int findLRU(int t[], int n) {
    int i, min = t[0], pos = 0;
    for (i = 1; i < n; i++)
        if (t[i] < min) { min = t[i]; pos = i; }
    return pos;
}

int main() {
    int pages[30], frames[10], time[10];
    int np, nf, i, j, count = 0, faults = 0, flag1, flag2, pos;

    printf("Enter number of pages: ");
    scanf("%d", &np);
    printf("Enter reference string: ");
    for (i = 0; i < np; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++) frames[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < np; i++) {
        flag1 = flag2 = 0;
        for (j = 0; j < nf; j++)
            if (frames[j] == pages[i]) {
                time[j] = ++count; flag1 = flag2 = 1; break;
            }
        if (!flag1)
            for (j = 0; j < nf; j++)
                if (frames[j] == -1) {
                    frames[j] = pages[i]; time[j] = ++count;
                    faults++; flag2 = 1; break;
                }
        if (!flag2) {
            pos = findLRU(time, nf);
            frames[pos] = pages[i]; time[pos] = ++count; faults++;
        }
        printf("%d\t", pages[i]);
        for (j = 0; j < nf; j++)
            frames[j] == -1 ? printf("- ") : printf("%d ", frames[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
