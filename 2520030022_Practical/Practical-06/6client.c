#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char message[100];
    char response[100];

    int fd1, fd2;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    // Send message to server
    fd1 = open("server_fifo", O_WRONLY);

    write(fd1, message, strlen(message) + 1);

    close(fd1);

    // Receive response from server
    fd2 = open("client_fifo", O_RDONLY);

    read(fd2, response, sizeof(response));

    printf("Server says: %s\n", response);

    close(fd2);

    return 0;
}
