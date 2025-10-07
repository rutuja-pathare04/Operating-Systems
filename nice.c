#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int ret;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        printf("Child process started (PID=%d)\n", getpid());

        // Increase priority (decrease nice value)
        ret = nice(-5);  // negative value => higher priority
        if (ret == -1) perror("nice");
        else printf("Child new nice value: %d\n", ret);

        for (int i = 0; i < 5; i++) {
            printf("Child running: %d\n", i);
            sleep(1);
        }
        printf("Child finished.\n");
    } else {        // Parent process
        printf("Parent process (PID=%d)\n", getpid());
        for (int i = 0; i < 5; i++) {
            printf("Parent running: %d\n", i);
            sleep(1);
        }
        wait(NULL);
        printf("Parent finished.\n");
    }

    return 0;
}
