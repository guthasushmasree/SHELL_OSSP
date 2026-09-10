#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char message[100];
    int fd1, fd2;

    mkfifo("server_fifo", 0666);
    mkfifo("client_fifo", 0666);

    printf("Server waiting...\n");

    fd1 = open("server_fifo", O_RDONLY);

    read(fd1, message, sizeof(message));

    printf("Client says: %s\n", message);

    close(fd1);

    // Send response
    fd2 = open("client_fifo", O_WRONLY);

    char response[] = "Hello Client, message received!";

    write(fd2, response, strlen(response) + 1);

    close(fd2);

    return 0;
}
