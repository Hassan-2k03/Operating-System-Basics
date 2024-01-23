#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int cpid = fork();
	int cpid2 = fork();
	if(cpid != 0 && cpid2 != 0)
	{
		int status;
		printf("\nParent: I am going to wait for process with ID: %d ",cpid2);
		//wait for any child to exit
		int waitPID = wait(&status);
		//wait for cpid2 to exit
		//int waitPID = wait(cpid2,&status,0);
		printf("\nPrarent: waited for child, return value of waitpid(): %d\n",waitPID);
		printf("\nPrarent: Exit code of terminated child: %d\n",WEXITSTATUS(status));
		exit(1);
	}
	else if (cpid ==0 && cpid2 != 0)
	{
		printf("\nChild1: My Process id: %d, myexit code 1\n",getpid());
		sleep(1);
		exit(1);	
	}
	else if (cpid !=0 && cpid2 == 0)
	{
		printf("\nChild2: My Process id: %d, myexit code 2\n",getpid());
		sleep(1);
		exit(2);	
	}	
	else
	{
		printf("\nChild3: My Process id: %d, myexit code 3\n",getpid());
		sleep(1);
		exit(3);
	}
	return 0;
}
