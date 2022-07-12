#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX 10
#define BUFFER_SIZE 100

struct msg_buffer
{
	long msg_type;
	char msg_txt(BUFFER_SIZE);

}message;

int main()
{
	key_t key;
	int msgid;
	printf("Enter the message you want to send\n");
	read(0,message.msg_txt, BUFFER_SIZE);
	printf("Message being sent %s\n", message.msg_txt);

	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.msg_type = 1;

	msgsnd(msgid, &message, sizeof(message),0);
	sleep(10);
	return 0;
}

