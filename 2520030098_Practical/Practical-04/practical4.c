#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int pid[3];
for(int i=0; i<3; i++)
{
pid[i]=fork();
if(pid[i]==0)
{
printf("child %d pid=%d\n",i+1,getpid());
sleep(i+1);
exit(0);
}
}
wait(NULL);
printf("parent: one child is completed with wait()\n");
waitpid(pid[2],NULL,0);
printf("parent: child 3 has completed with waitpid()\n");
wait(NULL);
printf("parent: all childs are completed\n");
}
