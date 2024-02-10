#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 25

int main()
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE]= "";
    int fd[2];
    pid_t pid;
    //cerate the pipe
    if(pipe(fd) == -1)
    {
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    //fork a child process
    pid = fork();
    if(pid > 0) //parent process
    {
        //close the unused end of the pipe
        close(fd[READ_END]);
        //write to the pipe
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
        //close the write end of the pipe
        close(fd[WRITE_END]);
        wait(NULL);
    }
    else if (pid == 0) //child process
    {
        //close the unused end of the pipe
        close(fd[WRITE_END]);
        //read from the pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("child process read: %s\n", read_msg);
        //close the read end of the pipe
        close(fd[READ_END]);
    }
    else //fork failed
    {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    return 0;
}