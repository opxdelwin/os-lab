//1. Create a pipe between a parent and child process and communicate data from parent to child through the pipe. Display the data in the parent process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int p[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    if (pipe(p) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(p[0]);
        if (write(p[1], message, strlen(message) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        close(p[1]);
    } else {
        close(p[1]);
        if (read(p[0], buffer, sizeof(buffer)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Received message in child: %s\n", buffer);
        close(p[0]);
    }

    return 0;
}

