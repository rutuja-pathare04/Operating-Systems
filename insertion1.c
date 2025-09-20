#include <stdio.h>
void insertion(int arr[], int n)
{
int i, j, key;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
 j--;
}
arr[j + 1] = key;
    }
}
int main()
{
    int arr[20], i, n;
    printf("How many numbers you want to sort: ");
    scanf("%d", &n);
    printf("Enter the actual values to sort:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    insertion(arr, n);

    printf("The sorted numbers are:\n");
    for (i = 0; i < n; i++)
    {
printf("%d\t", arr[i]);
}
    printf("\n");
    return 0;
}
