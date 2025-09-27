#include<stdio.h>

int n;

int findmax(int a[], int n);

int main() {
    int seq[30], fr[5], pos[5], find, flag, max, i, j, m, k, t, s;
    int count = 1, pf = 0, p = 0;
    float pfr;

    printf("Enter the maximum limit of seq: ");
    scanf("%d", &max);

    printf("\nEnter the sequence: ");
    for(i = 0; i < max; i++)
        scanf("%d", &seq[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &n);

    
    fr[0] = seq[0];
    pf++;
    printf("%d\t", fr[0]);
    i = 1;
    
 
    while(count < n) {
        flag = 1;
        p++;
        for(j = 0; j < i; j++) {
            if(seq[i] == seq[j]) {
                flag = 0;
                break;
            }
        }
        if(flag != 0) {
            fr[count] = seq[i];
            printf("%d\t", fr[count]);
            count++;
            pf++;
        }
        i++;
    }
    
    for(i = count; i < max; i++) {
        flag = 1;
        
     
        for(j = 0; j < n; j++) {
            if(seq[i] == fr[j]) {
                flag = 0;
                break;
            }
        }

   
        if(flag != 0) {
          
            for(j = 0; j < n; j++) {
                pos[j] = -1;
                for(k = i + 1; k < max; k++) {
                    if(fr[j] == seq[k]) {
                        pos[j] = k;
                        break;
                    }
                }
            }

      
            s = findmax(pos, n);

         
            fr[s] = seq[i];
            for(k = 0; k < n; k++) {
                printf("%d\t", fr[k]);
            }
            pf++;
            printf("\n");
        }
    }

  
    pfr = (float)pf / (float)max;

    printf("\nThe number of page faults is: %d", pf);
    printf("\nPage fault rate: %f\n", pfr);

    return 0;
}
int findmax(int a[], int n) {
    int max = -1, i, k = 0;
    
    for(i = 0; i < n; i++) {
        if(a[i] == -1) {
            return i;
        }
        if(a[i] > max) {
            max = a[i];
            k = i;
        }
    }
    return k;
}

