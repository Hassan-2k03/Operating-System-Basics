/* Create a global array with values [1,6,2,4,5,8,9,0]. Sort the same within the child process, and 
display the values in the parent process. Are the displayed values in the sorted order? 
If not, why? Note: No interprocess communication */

//code: 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    pid_t pid;
    int arr[] = {1,6,2,4,5,8,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
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
        int i, j, temp;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        printf("Sorted array: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        //Parent will wait for the child to complete
        wait(NULL);
        printf("Child Complete\n");
        printf("Parent Process: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}