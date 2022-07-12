#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define BUFFER_SIZE 100

struct msg_buf
{
	long msg_type;
	char msg_txt[BUFFER_SIZE];
}message;

int main()
{
	key_t key;
	int msgid;
	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);

	msgrcv(msgid, &message, sizeof(message),1,0);
	printf("The message received is: %s\n", message.msg_txt);
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}