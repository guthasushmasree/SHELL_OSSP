#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>//for exit systemcall
int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("child process %d\n",getpid());
exit(0);
}
else
{
printf("parent process %d\n",getpid());
sleep(30);//wait 30 milliseconds
printf("parent process completed\n");
}
}
