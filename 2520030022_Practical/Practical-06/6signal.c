#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
    if (sig == SIGINT)
        printf("\nSIGINT received!\n");

    else if (sig == SIGTERM)
        printf("\nSIGTERM received!\n");

    else if (sig == SIGUSR1)
        printf("\nSIGUSR1 received!\n");
}

int main()
{
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    signal(SIGUSR1, handle_signal);

    printf("Program started...\n");
    printf("Process ID: %d\n", getpid());

    while (1)
    {
        printf("Program is running...\n");
        sleep(3);
    }

    return 0;
}
