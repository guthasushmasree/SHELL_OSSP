#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h> //used for wait() and waitpid() system calls
#include<stdlib.h> //used for exit() system call
int main()
{
int pid[3]; //initializing 3 childs
for(int i=0;i<3;i++) //to navigate through all childs
{
pid[i]=fork(); //creating 3 childs
if(pid[i]==0) //indicates child process
{
printf("Child %d=%d\n",i+1,getpid());
sleep(i+1); //giving a pause after every child
exit(0); //exit from standard input
}
}
wait(NULL); //waiting for any one child
printf("Parent: One child is completed with wait()\n");
waitpid(pid[2],NULL,0); //waiting for the specific pid
printf("Parent: Child 3 has completed with waitpid()\n");
wait(NULL); //waiting for the last child to completed
printf("Parent: All childs are completed\n"); //parent is returning the last child status
}
}
