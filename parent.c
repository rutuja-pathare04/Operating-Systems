#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    // Convert sorted array to string arguments
    char *args[n+3]; // program name + n elements + NULL + item to search
    args[0] = "./child"; // child program executable
    for(int i=0;i<n;i++){
        args[i+1] = malloc(10);
        sprintf(args[i+1], "%d", arr[i]);
    }
    args[n+1] = NULL; // execve requires NULL terminated array

    if(fork() == 0){
        execve("./child", args, NULL); // execute child program
        perror("execve failed");
        exit(1);
    } else {
        wait(NULL); // parent waits
    }

    // Free allocated memory
    for(int i=1;i<=n;i++) free(args[i]);

    return 0;
}
