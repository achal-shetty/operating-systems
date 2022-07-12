#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t p1 = fork();
	if(p1>0)
	{
		printf("Parent ID = %d\n", getpid());
		exit(0);
	}
	else if(p1 == 0)
	{
		sleep(30);
		printf("In child process executed now = %d, and PPID = %d\n", getpid(), getppid());
	}
	return 0;
}