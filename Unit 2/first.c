#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
	char write_msg[BUFFER_SIZE] = "Welcome to IPC";
	char read_msg[BUFFER_SIZE] = " ";
	int fd[2];
	pid_t pid;


	if(pipe(fd) == 1)
	{
		printf("Pipe Failed!!!\n");
		return 1;
	}

	pid = fork();
	if (pid>0)
	{
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		close(fd[WRITE_END]);
		wait(NULL);
	}
	else if(pid == 0)
	{
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		close(fd[READ_END]);
	}
	else
	{
		printf("Fork Failed!!!\n");
	}
}