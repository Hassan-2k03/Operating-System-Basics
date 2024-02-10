#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main()
{
    int fd;
    char buffer[BUFFER_SIZE] ="";
    //FIFO file path
    char * myfifo = "/tmp/myfifo";
    printf("Enter the message to be sent to the FIFO: ");
    read(0, buffer, BUFFER_SIZE);
    //creating the named file(FIFO)
    mkfifo(myfifo, 0666);
    fd = open(myfifo, O_WRONLY);
    write(fd, buffer, BUFFER_SIZE);
    //close the write end of the pipe
    close(fd);
    sleep(100);
    return 0;
}