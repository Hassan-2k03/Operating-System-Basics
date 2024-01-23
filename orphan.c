// Program to demo orphan process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	
	if(pid>0) // Parent process
	{
		printf("In parent process process id = %d\n",getpid());
		exit(0);
	}
	
	else if (pid == 0) // child process
	{
		sleep(30);
		printf("In child process. Process id = %d, parent process id = %d\n", getpid(),getppid()); 
	}
	
	return 0;
}
