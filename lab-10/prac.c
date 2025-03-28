#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main() {
    int p[2]; // p[0]-reading, p[1]-writing
    int r = pipe(p); // 1=success, -1=failure

    if (r < 0) {
        exit(EXIT_FAILURE); // Terminating with failure status
    }

    pid_t pid = fork(); // Declare pid variable to store the return value of fork()

    if (pid < 0) {
        perror("Fork failed"); // Print error message if fork fails
        exit(EXIT_FAILURE); // Terminating with failure status
    }

    if (pid > 0) {
        // Parent process
        char *s1 = "Hello from parent!\n";
        size_t size = strlen(s1) + 1; // Adding 1 to include null terminator
        close(p[0]); // Close the reading end of the pipe

        // Write data to the pipe
        write(p[1], s1, size);
        close(p[1]); // Close the writing end of the pipe
        wait(NULL); // Wait for child process to finish
    } else {
        // Child process
        char input[100]; // Assuming a maximum size for input
        close(p[1]); // Close the writing end of the pipe

        // Read data from the pipe
        ssize_t bytes_read;
        while ((bytes_read = read(p[0], input, sizeof(input))) > 0) {
            // Print the data read from the pipe
            printf("%.*s", (int)bytes_read, input);
        }
        close(p[0]); // Close the reading end of the pipe
    }

    return 0;
}

