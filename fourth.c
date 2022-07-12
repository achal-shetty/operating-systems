//fork() and wait()

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t p1;
	int y=0;
	p1= fork();

	if(p1>0)
	{
		wait(NULL);
		y=y+1;
		printf("Parent Process ID = %d\n, y=%d\n", getpid(),y);
	}
	else if(p1==0)
	{
		y=y+1;
		printf("Child Process ID = %d\n, y=%d\n", getpid(),y);
		exit(0);
	}
	else
	{
		printf("Fork Failed!!");
	}
}