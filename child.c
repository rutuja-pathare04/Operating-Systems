#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key){
    int low=0, high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("No array received!\n");
        return 1;
    }

    int n = argc - 1;
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=atoi(argv[i+1]);

    printf("Sorted array received in child: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");

    int key;
    printf("Enter the item to search: ");
    scanf("%d", &key);

    int idx = binarySearch(arr, n, key);
    if(idx != -1) printf("Item %d found at position %d\n", key, idx+1);
    else printf("Item %d not found\n", key);

    return 0;
}
