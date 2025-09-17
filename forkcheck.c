// C Program to create a new process using Linux API system calls fork() and exit()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>   // for wait()

int main() {
    int pid = fork();   // Create a new process

    if (pid == 0) { 
        // Child process
        printf("I am child, my PID is %d\n", getpid()); 
        printf("My parent PID is: %d\n", getppid()); 
        sleep(2);  // Keep child alive for verification
        exit(0);   // Child exits
    } 
    else if (pid > 0) { 
        // Parent process
        printf("I am parent, my PID is %d\n", getpid()); 
        wait(NULL);   // Wait for child to finish
        printf("Child process has finished.\n");
        exit(0);      // Parent exits
    } 
    else {
        // Error case
        perror("fork failed");
        exit(1);
    }
}
