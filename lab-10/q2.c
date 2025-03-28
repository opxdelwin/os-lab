//2. Create 4 child processes and each child process communicates with the parent process using pipe. Each child process performs different types of operations (addition, subtraction, multiplication and division). At the beginning, parent process shares the input data (2 numbers) with all the child processes. After receiving the data, each child process performs the operation and sends the result back to the parent process, so that parent process can display the results.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to perform addition
int addition(int a, int b) {
    return a + b;
}

// Function to perform subtraction
int subtraction(int a, int b) {
    return a - b;
}

// Function to perform multiplication
int multiplication(int a, int b) {
    return a * b;
}

// Function to perform division
int division(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

int main() {
    int numbers[2]; // Input data (2 numbers)
    int result;     // Result received from child processes
    int pipes[4][2]; // Array of pipes for communication with child processes

    // Create pipes
    for (int i = 0; i < 4; i++) {
        if (pipe(pipes[i]) < 0) {
            perror("Pipe creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Input data
    printf("Enter two numbers: ");
    scanf("%d %d", &numbers[0], &numbers[1]);

    // Create 4 child processes
    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            close(pipes[i][0]); // Close reading end of pipe in child
            switch (i) {
                case 0:
                    result = addition(numbers[0], numbers[1]);
                    break;
                case 1:
                    result = subtraction(numbers[0], numbers[1]);
                    break;
                case 2:
                    result = multiplication(numbers[0], numbers[1]);
                    break;
                case 3:
                    result = division(numbers[0], numbers[1]);
                    break;
                default:
                    printf("Invalid child process index\n");
                    exit(EXIT_FAILURE);
            }
            write(pipes[i][1], &result, sizeof(int)); // Write result to pipe
            close(pipes[i][1]); // Close writing end of pipe in child
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process
    for (int i = 0; i < 4; i++) {
        close(pipes[i][1]); // Close writing end of all pipes in parent
    }

    // Wait for all child processes to complete and collect results
    for (int i = 0; i < 4; i++) {
        wait(NULL);
        read(pipes[i][0], &result, sizeof(int)); // Read result from pipe
        switch (i) {
            case 0:
                printf("Addition result: %d\n", result);
                break;
            case 1:
                printf("Subtraction result: %d\n", result);
                break;
            case 2:
                printf("Multiplication result: %d\n", result);
                break;
            case 3:
                printf("Division result: %d\n", result);
                break;
            default:
                printf("Invalid child process index\n");
        }
    }

    return 0;
}
