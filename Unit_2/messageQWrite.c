//program to demo messafe quew write

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define BUF_SIZE 100

//structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[BUF_SIZE];
} message;

int main()
{
    key_t key;
    int msgid;
    
    printf("Enter the message to be sent to the message queue: ");
    fgets(message.mesg_text, BUF_SIZE, stdin);
    read(0, message.mesg_text, BUF_SIZE);

    printf("Message entered: %s\n", message.mesg_text);

    //ftok to generate unique key   
    key = ftok("progfile", 65);

    //msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    //msgsnd to send message    
    msgsnd(msgid, &message, sizeof(message), 0);

    sleep(5);
}