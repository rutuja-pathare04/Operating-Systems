#include <stdio.h>

int main() {
    int n, i, j, k, pageFaults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &n);

    int frames[n];
    for(i=0;i<n;i++) frames[i] = -1; // initialize frames

    int refStr[] = {8,5,7,8,5,7,2,3,7,3,5,9,4,6,2};
    int refLen = sizeof(refStr)/sizeof(refStr[0]);

    int freq[100] = {0}; // frequency of each page

    printf("Page sequence: \n");

    for(i=0;i<refLen;i++){
        int found = 0;
        // check if page already in frame
        for(j=0;j<n;j++){
            if(frames[j] == refStr[i]){
                found = 1;
                freq[refStr[i]]++; // increment frequency
                break;
            }
        }

        if(!found){
            // check for empty frame
            int empty = -1;
            for(j=0;j<n;j++){
                if(frames[j] == -1){
                    empty = j;
                    break;
                }
            }

            if(empty != -1){
                frames[empty] = refStr[i];
                freq[refStr[i]] = 1;
            } else {
                // find MFU page to replace
                int maxFreq = -1, mfuIndex = -1;
                for(j=0;j<n;j++){
                    if(freq[frames[j]] > maxFreq){
                        maxFreq = freq[frames[j]];
                        mfuIndex = j;
                    }
                }
                frames[mfuIndex] = refStr[i];
                freq[refStr[i]] = 1;
            }
            pageFaults++;
        }

        // display current frames
        printf("After inserting %d: ", refStr[i]);
        for(j=0;j<n;j++){
            if(frames[j]!=-1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
