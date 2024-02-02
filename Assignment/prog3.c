/* Write a program which accepts two integers x and y. Now use exe to execute another user defined 
program prints the product of x and y */

//Code: 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    //Write a program which accepts two integers x and y
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    //Now use exe to execute another user defined  program prints the product of x and y
    pid_t pid;
    // fork a child process
    pid = fork();

}