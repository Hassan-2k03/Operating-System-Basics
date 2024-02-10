#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void *shared_memory;
    char buffer[100] = "";
    int shmid;

    shmid = shmget((key_t)2345, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    //process attached to shared memory
    printf("Process attached at %X\n", (int)shared_memory);
    printf("Enter some data to write to the shared memory: ");
    read(0, buffer, 100);
    strcpy(shared_memory, buffer);
    printf("You wrote: %s\n", (char *)shared_memory);
    return 0;
}
