#include<stdio.h>
void insertion(int arr[],int n)
{
int i,j,key;
for(i=1;i<n;i++) 
{
key=arr[i];
j=i-1;
while(j>=0 && arr[j]>key) 
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;

}
int binarySearch(int arr[],int n,int target)
{
int low=0,high=n-1;
while(low <= high) 
{
int mid=low+(high-low)/2;
if(arr[mid] == target)
return mid; 
else if(arr[mid]<target)
low=mid+1;
else
high=mid-1;
}
return -1; 
}
int main() 
{
int arr[20],i,n,target,index;
printf("How many numbers you want to sort: ");
scanf("%d",&n);
printf("Enter the actual values to sort:\n");
for(i=0;i<n;i++)
{
printf("Element %d: ",i+1);
scanf("%d",&arr[i]);
}
insertion(arr,n);
printf("The sorted numbers are:\n");
for(i=0;i<n;i++) {
printf("%d\t",arr[i]);
}
printf("\n");
printf("Enter the element to search: ");
scanf("%d",&target);
index=binarySearch(arr,n,target);
if(index!=-1)
printf("Element %d found at position %d (0-based index)\n",target,index);
else
printf("Element %d not found in the array.\n",target);
return 0;
}
}
