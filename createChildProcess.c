#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t p1, p2;
	int y = 0;
	p1 = fork();
	if(p1>0) // parent process
	{
		wait(NULL);
		y = y - 1;
		printf("This is parent, process id = %d, y = %d\n",getpid(), y);
		execlp("/bin/ls","ls",NULL);		
	}
	else if(p1 == 0)
	{
		p2 = fork();
		if (p2>0)
			wait(NULL);
		else if (p2==0)
		{
			y=y+5;
			printf("This is grandchild. Process id %d, Parent process id %d, y=%d\n",getpid(),getppid(),y);
			exit(0);
		}	
		y=y+1;
		printf("THis is child. process id %d, parent process id %d, y = %d\n", getpid(),getppid(),y);
		char *a[] = {NULL};
		execv("/home/hassan_2k03/Desktop/Os_Programs/createChildProcess.exe",a);
		exit(0);
	}
	else 
	{
		printf("fork creation failed!!!");
	}
}
