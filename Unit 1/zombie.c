// Program to demo zombie process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if(pid>0) // Parent process
	{
		sleep(30);
		printf("In parent process process id = %d\n",getpid());
	}
	else if (pid == 0) // child process
	{
		printf("In child process. Process id = %d, parent process id = %d\n", getpid(),getppid()); 
		exit(0);
	}
	return 0;
}
