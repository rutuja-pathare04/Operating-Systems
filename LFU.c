#include <stdio.h>

int findLFU(int freq[], int n) {
    int i, min = freq[0], pos = 0;
    for (i = 1; i < n; i++)
        if (freq[i] < min) { min = freq[i]; pos = i; }
    return pos;
}

int main() {
    int pages[30], frames[10], freq[10];
    int np, nf, i, j, k, faults = 0, flag, pos;

    printf("Enter number of pages: ");
    scanf("%d", &np);
    printf("Enter reference string: ");
    for (i = 0; i < np; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &nf);

    for (i = 0; i < nf; i++) { frames[i] = -1; freq[i] = 0; }

    printf("\nPage\tFrames\n");
    for (i = 0; i < np; i++) {
        flag = 0;

        // Check if page exists
        for (j = 0; j < nf; j++)
            if (frames[j] == pages[i]) {
                freq[j]++; flag = 1; break;
            }

        // If not found
        if (!flag) {
            for (j = 0; j < nf; j++)
                if (frames[j] == -1) {
                    frames[j] = pages[i]; freq[j] = 1;
                    faults++; flag = 1; break;
                }
        }

        // Replace LFU page
        if (!flag) {
            pos = findLFU(freq, nf);
            frames[pos] = pages[i];
            freq[pos] = 1;
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
