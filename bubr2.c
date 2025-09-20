#include<stdio.h>
void bubblesort(int arr[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(arr[j]>arr[j+1]) 
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
int main()
{
int arr[20],i,n;
printf("How many numbers you want to sort: ");
scanf("%d",&n);
printf("Enter the actual values to sort:\n");
for(i=0;i<n;i++)
{
printf("Element %d: ",i+1);
scanf("%d",&arr[i]);
}
bubblesort(arr,n);
printf("The sorted numbers are:\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\n");
return 0;
}

