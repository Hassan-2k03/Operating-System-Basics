/* Write a program to create child process which lists all the executing user process 
(avoid creation of zombie process). */

//code: 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    // fork a child process
    pid = fork();
    
    if (pid < 0)
    {
        // Error Occurred
        fprintf(stderr,"Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child Process
        execlp("/bin/ls","ls",NULL);
    }
    else
    {
        //Parent will wait for the child to complete
        wait(NULL);
        printf("Child Complete\n");
    }
    return 0;
}