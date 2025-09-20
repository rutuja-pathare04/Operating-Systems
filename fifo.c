/*#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf("Enter the Number of Pages:\n");
scanf("%d",&n);
printf("Enter the Page Number(Reference String):\n");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("Enter the Number fo Frames:\n");
for(i=0;i<no;i++)
frame[i]=-1;
j-0;
printf("\t Ref string\t page Frames\n");
for(i=0;i<=n;i++)
{
printf("%d\t\t",a[i]);
avail=0;
for(k=0;k<no;k++)
if(frame[k]==a[i]);
avail=1;
if(avail==0)
{
frame[j]=a[i];
j=(j+1)%no;
count++;
}
}
for(k=0;k<no;k++)
printf("%d\t",frame[k]);
printf("\n");
printf("Page Fault is %d",count);
return 0;
} */

#include <stdio.h>

int main()
{
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;

    printf("Enter the Number of Pages:\n");
    scanf("%d", &n);

    printf("Enter the Page Number (Reference String):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the Number of Frames:\n");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0; // Initialize pointer for FIFO replacement

    printf("\nRef String\tPage Frames\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;

        // Check if page is already in frame
        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
            {
                avail = 1;
                break;
            }
        }

        // If page not found in frame, replace using FIFO
        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
        }

        // Print current frame contents
        for (k = 0; k < no; k++)
        {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", count);

    return 0;
}


