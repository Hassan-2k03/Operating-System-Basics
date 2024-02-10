// program to demo - FIFO read

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main()
{
    int fd1;
    char buffer[BUFFER_SIZE] ="";
    //FIFO file path
    char * myfifo = "/tmp/myfifo";
    //creating the named file(FIFO)
    mkfifo(myfifo, 0666);
    //open in read only and read
    fd1 = open(myfifo, O_RDONLY);
    read(fd1, buffer, BUFFER_SIZE);
    //print the read string and close
    printf("Read info: %s\n", buffer);
    close(fd1);
    //unlink the FIFO
    unlink(myfifo);
    return 0;
}