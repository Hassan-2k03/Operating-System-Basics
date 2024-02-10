/* Write a program which accepts two integers x and y. Now use exe to execute another user 
defined program prints the product of x and y */

// code: 

#include <stdio.h>
#include <unistd.h>

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    char arg1[10], arg2[10];
    sprintf(arg1, "%d", x);
    sprintf(arg2, "%d", y);

    execlp("./p3prod", "p3prod", arg1, arg2, NULL);

    return 0;
}