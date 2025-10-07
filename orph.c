#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        printf("Child started. PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(5);  // Give time for parent to terminate
        printf("Child after parent terminates. PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Child finished.\n");
    } else {       // Parent process
        printf("Parent PID = %d, creates child PID = %d\n", getpid(), pid);
        printf("Parent terminating now.\n");
        exit(0);    // Parent terminates before child
    }

    return 0;
}
