// demonstrate of creation of child and grandchild using fork(), wait()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t p1,p2;
	int y = 0;
	p1 = fork();
	if(p1>0) //parent process
	{
		wait(NULL);
		y = y - 1;
		printf("This is parent.Process id = %d, y = %d\n", getpid(),y);
	}
	else if (p1 == 0)
	{
		p2 = fork();
		if(p2>0)
			wait(NULL);
		else if(p2 == 0)
		{
			y=y+5;
			printf("This is grandchild,Process id %d, Parent Process id %d,y=%d\n",getpid(),getppid(),y);
			exit(0);
		}
		y=y+1;
		printf("This is child. Process id = %d, Parent process %d, y=%d\n",getpid(),getppid(),y);
		exit(0); 
	}
	else // fork failed
	{
		printf("fork creation failed !!!\n");
	}
}
