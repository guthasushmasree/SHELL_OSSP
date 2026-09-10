#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h> // for wait syscall
#include<time.h>// for clocks_per_sec and clock() sys call
int main()
{
int fd[2];//parameter for anonymous pipe
int data;//variable that writes data to pipe
int start,end;// variables that take start and end times
double timetaken;//variable that calculates the communication time
double efficiency;
pipe(fd);//creating a anonymous pipe
start=clock();//storing the start time
if(fork()==0)//creating a child as consumer
{
close(fd[1]);//closing the write end of the pipe
printf("Consumer \n");//starting the consumer
for(int i=0;i<5;i++)//getting the consumer data from the pipe
{
read(fd[0],&data,sizeof(data));//consumer is reading the data from the pipe
printf("Consumed %d\n",data);//printing the reada data
}
close(fd[0]);//closing the read end of the pipe in the child
}
else
{
close(fd[0]);//closing the read end of the pipe in parent
printf("Producer \n");//initializing the parent with producer
for(int i=1;i<=5;i++)//defining the producer data
{
data=i*10;
write(fd[1],&data,sizeof(data));//writing data in the producer
printf("Produced %d\n",data);//printing the produced data
}
close(fd[1]);//closing the write end of the pipe
wait(NULL);//parent waits for the child to complete
end=clock();//closing the clock to take the communication time
timetaken=(double)(end-start)/CLOCKS_PER_SEC;//calculating the overall time
printf("Communication time is %lf\n", timetaken);//printing the timetaken
efficiency=5/timetaken;
printf("Efficiency is %lf\n", efficiency);
}
}
