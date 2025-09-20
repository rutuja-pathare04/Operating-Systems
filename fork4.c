#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void ChildProcess();
void ParentProcess();
int getppid();
int getpid();
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
ChildProcess();
else
ParentProcess();
return 0;
}
void ChildProcess()
{
printf("\n I am Child Process.\n\t");
printf("\nThe process id is:%d \n\t",getpid());
}
void ParentProcess()
{
printf("\n I am Parent process.\n\t");
printf("\n The process id is: %d \n \t",getppid());
}

