//producerconsumer.c
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>//for using wait() systemcall
#include<time.h>//for clocks_per_sec and clock() systemcall
int main()
{
int fd[2];//parameter for anonymous pipes
int data;//variable that writes data to pipe
int start,end;//variables that take start and end times;
double timetaken,communication_efficiency;//variable that calculated the communication time
pipe(fd);//creating anonymous pipes
start=clock();//storing the start time
if(fork()==0)//creating a child as a consumer
{
close(fd[1]);//closing the write end of the pipe
printf("consumer\n");//starting the consumer
for(int i=0;i<5;i++)//getting the consumer data from the pipe
{
read(fd[0],&data,sizeof(data));//consumer is reading the data from the pipe
printf("consumed %d\n",data);//print the read data
}
close(fd[0]);//closing the read end of the pipe in the child
}
else
{
close(fd[0]);//closing the read end of the pipe in the parent 
printf("producer\n");//initializing the parent with producer
for(int i=1;i<=5;i++)//defining the producer  data
{
data=i*10;//initializing the data values in the producer
write(fd[1],&data,sizeof(data));//writing data into the pipe
printf("produced %d\n",data);//printing the produced data
}
close(fd[1]);//closing the write end of the pipe
wait(NULL);//parent waits for child to complete
end=clock();//closing the clock to take the communication time
timetaken=(double)(end-start)/CLOCKS_PER_SEC;//calculating the overall time
printf("communication time: %lf\n",timetaken);//printing the time taken 
communication_efficiency=(5)/timetaken;
printf("communication effiency %lf\n",communication_efficiency);
}
}
