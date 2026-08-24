#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define BUFFER_SIZE 100

// Read a single character from keyboard
char getch() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int main() {
    char input[BUFFER_SIZE];
    int index;

    while (1) {
        index = 0;

        // Display prompt
        printf("myshell> ");
        fflush(stdout);

        // Read keyboard input
        while (1) {
            char ch = getch();

            // Enter key
            if (ch == '\n' || ch == '\r') {
                input[index] = '\0';
                printf("\n");
                break;
            }

            // Backspace key
            if (ch == 127 || ch == '\b') {
                if (index > 0) {
                    index--;
                    printf("\b \b");
                    fflush(stdout);
                }
                continue;
            }

            // Store normal characters
            if (index < BUFFER_SIZE - 1) {
                input[index++] = ch;
                printf("%c", ch);
                fflush(stdout);
            }
        }

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // Handle commands
        if (strcmp(input, "hello") == 0) {
            printf("Hello! Welcome to the shell.\n");
        }
        else if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  hello - Display greeting\n");
            printf("  help  - Display commands\n");
            printf("  exit  - Exit the shell\n");
        }
        else if (strlen(input) > 0) {
            printf("You entered: %s\n", input);
        }
    }

    return 0;
}
