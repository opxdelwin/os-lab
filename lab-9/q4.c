//Use fork() to create 1 child process from one parent process and another child process from the child process (P1->P2->P3) and display the PID and PPID. Execute them -
//(i) With wait() function


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p;
    p=fork();
    if(p==0){
            fork();
            printf("Child PID:%d\tParent PID:%d\n",getpid(),getppid());
            exit(EXIT_SUCCESS);
    }else if(p > 0){
            printf("Parent Process PID: %d\n",getpid());
            wait(NULL);
    }
    return 0;
}
