#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char buf[50];
    int pid;

    printf("Enter a Linux command: ");
    scanf("%s", buf);

    pid = fork();

    if(pid == 0)
    {
        printf("\n--- Child Process ---\n");
        printf("Child ID: %d\n", getpid());
        printf("Parent ID: %d\n", getppid());

        execlp(buf, buf, NULL);

        printf("Unable to execute the command\n");
    }
    else if(pid > 0)
    {
        printf("\n--- Parent Process ---\n");
        printf("Parent ID: %d\n", getpid());
        printf("Parent's Parent ID: %d\n", getppid());

        wait(NULL);

        printf("Child process has finished execution\n");
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
