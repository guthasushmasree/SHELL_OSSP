#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
int pid;
char buff[50];
printf("Enter Linux Command:");
scanf("%s",buff);
pid=fork();
if(pid==0){
printf("Child Process\n");
printf("Child PID: %d\n",getpid());
printf("Parent PID: %d\n",getppid());
execlp(buff,buff,NULL);
}
else if(pid>0){
printf("Parent Process\n");
printf("Parent PID: %d\n",getpid());
wait(NULL);
printf("Child Process Completed\n");
}
else{
printf("Fork failed\n");
}
return 0;
}
