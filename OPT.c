#include <stdio.h>
int findOptimal(int pages[], int frames[], int n, int index, int total) {
    int pos = -1, farthest = index, i, j;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = index; j < total; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if (!found)
            return i;
    }
    return (pos == -1) ? 0 : pos;
}
int main() {
    int pages[30], frames[10];
    int np, nf, faults = 0, i, j, k, flag, pos;

    printf("Enter number of pages: ");
    scanf("%d", &np);
    printf("Enter reference string: ");
    for (i = 0; i < np; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++) frames[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < np; i++) {
        flag = 0;
        for (j = 0; j < nf; j++)
            if (frames[j] == pages[i]) { flag = 1; break; }

        if (!flag) {
            if (i < nf)
                frames[i] = pages[i];
            else {
                pos = findOptimal(pages, frames, nf, i + 1, np);
                frames[pos] = pages[i];
            }
            faults++;
        }

        printf("%d\t", pages[i]);
        for (k = 0; k < nf; k++)
            frames[k] == -1 ? printf("- ") : printf("%d ", frames[k]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

