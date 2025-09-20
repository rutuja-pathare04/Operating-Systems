#include<stdio.h>
int main()
{
int i,j,n;
printf("Enter the number of processes:");
scanf("%d",&n); 
int process[n],arrivalTime[n],burstTime[n],startTime[n],completionTime[n],turnAroundTime[n],waitingTime[n];
float totalTAT=0,totalWT=0;
 for(i=0;i<n;i++)
 {
 
 process[i]=i+1;
 printf("Enter Arrival Time and Burst Time of Process %d:",i+1);
 scanf("%d %d",&arrivalTime[i],&burstTime[i]);
 }
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
 if(arrivalTime[i]>arrivalTime[j])
 {
 int temp=arrivalTime[i];
 arrivalTime[i]=arrivalTime[j];
 arrivalTime[j]=temp;
  
  temp=burstTime[i];
  burstTime[i]=burstTime[j];
  burstTime[j]=temp;
  
  temp=process[i];
  process[i]=process[j];
  process[j]=temp;
  }
  }
  }
  for(i=0;i<n;i++)
  {
  if(i==0)
  {
  startTime[i]=arrivalTime[i];
  }
  else
  {
  startTime[i]=startTime[i-1]+burstTime[i-1];
  }
  completionTime[i]=startTime[i]+burstTime[i];
  turnAroundTime[i]=completionTime[i]-arrivalTime[i];
  waitingTime[i]=turnAroundTime[i]-burstTime[i];
  
  totalTAT+=turnAroundTime[i];
  totalWT+=waitingTime[i];
  }
   printf("\nProcess\tAT\tBT\tST\tCT\tTAT\tWT\n");
  for(i=0;i<n;i++)
  {
  printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               process[i], arrivalTime[i], burstTime[i],
               startTime[i], completionTime[i],
               turnAroundTime[i], waitingTime[i]);
    }
  printf("\n Average Turn Around Time:%.2f\n",totalTAT /n);
    printf("\n Average Waiting Time:%.2f\n",totalWT /n );
    printf("Gantt Chart:\n");
    for(i=0;i<n;i++)
    {
    printf("P%d|",process[i]);
    }
    printf("\n0");
    for(i=0;i<n;i++)
    {-
    printf("  %d",completionTime[i]);
    }
    printf("\n");
    return 0;	
    }
    
    
  
  
  
 
 
