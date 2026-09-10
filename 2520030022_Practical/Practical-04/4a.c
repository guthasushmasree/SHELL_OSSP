#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h> // for wait() and waitpid() systemcalls
#include<stdlib.h> // for using exit sys call
int main()
{
int pid[3]; // initializing 3 child
for(int i=0;i<3;i++) // loop runs for 3 childs
{
pid[i]=fork(); // creating 3 childs
if(pid[i]==0) // indicates a child process
{
printf("Child %d pid=%d\n",i+1,getpid());
sleep(i+1); // giving a pause after every child
exit(0); // exit standard input
}
}
wait(NULL); // waiting for any one child
printf("Parent : one child is completed with wait()\n");
waitpid(pid[2],NULL,0); // waiting using a specific child pid
printf("Parent: Child 3 has completed with wait pid()\n");
wait(NULL); // waiting for all childs
printf("Parent: All the childs are completed\n");
}
