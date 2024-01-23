// Program to demo fork process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t p1;
	int y = 0;
	p1 = fork();
	if(p1>0) // parent process 
	{
		y=y-1;
		printf("This is parent. Parent process id:%d, y = %d\n",getpid(),y);
	}	
	
	else if(p1 == 0) //child process
	{
		y=y+1;
		printf("This is child. Child process id:%d,Parent process id = %d,y = %d\n",getpid(),getppid(),y);
	}
	else // fork failed
	{
		printf("fork creation failed!!!\n");
	}
	return 0;
}	
