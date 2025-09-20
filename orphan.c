#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t pid;
pid=fork();
if(pid!=0)
{
printf("The Process ID of Parent Process:%d\n",getpid());
sleep(5);
}
else
{
printf("\nThe Process ID of Child Process is:%d\n",getpid());
printf("The Process ID of Parent Process:%d\n",getppid());
sleep(10);
printf("\nThe Process ID of Child Process is:%d\n",getpid());
printf("\nThe Process ID of Parent Process after termination is:%d\n",getppid());
}
}




