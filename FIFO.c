#include <stdio.h>

int main() {
    int pages[30], frames[10];
    int np, nf, i, j, k, faults = 0, front = 0, flag;

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
            frames[front] = pages[i];
            front = (front + 1) % nf;
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
