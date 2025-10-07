#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}

void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++){
        int key=arr[i], j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int arr[n], arr2[n];
    printf("Enter %d integers: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        arr2[i] = arr[i]; // copy for child
    }

    pid_t pid = fork();

    if(pid < 0){
        perror("fork failed");
        exit(1);
    }

    if(pid == 0){ // Child process
        printf("\nChild process: Sorting using Insertion Sort\n");
        insertionSort(arr2, n);
        printf("Child sorted array: ");
        printArray(arr2, n);
        exit(0);
    } else { // Parent process
        wait(NULL); // wait for child
        printf("\nParent process: Sorting using Bubble Sort\n");
        bubbleSort(arr, n);
        printf("Parent sorted array: ");
        printArray(arr, n);
    }

    return 0;
}
