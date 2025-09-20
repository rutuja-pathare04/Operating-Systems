#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void bubblesort(int arr[],int n);
void insertion(int arr[],int n);

int main()
{
int arr[30],i,n,key;
printf("How many numbers you want to sort: ");
scanf("%d",&n);
printf("Enter the actual values to sort:\n");
for(i=0;i<n;i++)
{
printf("Element %d: ",i+1);
scanf("%d",&arr[i]);
}

pid_t pid;
pid=fork();
if(pid==0)
{

insertion(arr,n);

printf("The sorted numbers in Child Process are:\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\n");
return 0;
}

else
{

bubblesort(arr,n);

printf("The sorted numbers in Parent Process are:\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\n");
}
return 0;
}


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
void insertion(int arr[],int n)
{
int i,j,key;
for(
i=1;i<n;i++)
{
key=arr[i];
j=i-1;
while(j>=0 &&arr[j]>key)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
}


