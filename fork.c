#include<stdio.h>
#include<sys/types.h>
void ChildProcess();
void ParentProcess();
int main()
{
pid_tpid;
pid=fork();
if(pid==0)
ChildProcess();
else
ParentProcess();
return();
}
void ChildProcess()
{
printf("I am Child Process.");
}
void ParentProcess()
{
printf("I am Parent Child process.");
}

