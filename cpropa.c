#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork(); // create child process

    if (pid < 0) {
        // fork failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("I am Child Process. PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("I am Parent Process. PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
