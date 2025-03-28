#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p;

    for (int i = 1; i <= 5; i++) {
        p = fork();

        if(p==0){
                printf("Child PID:%d\tParent PID:%d\n",getpid(),getppid());
                exit(EXIT_SUCCESS);
        }else if(p > 0){
                printf("Parent Process PID: %d\n",getpid());
                wait(NULL);
        }
    }

    return 0;
}
