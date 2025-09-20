#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int pid=fork();
if(pid==0)
{
char*args[]={"./fork4",NULL};
execvp(args[0],args);
printf("I am a Child Process.\n");
}
else
{
printf("I am Parent Process.\n");
}
return 0;
}

