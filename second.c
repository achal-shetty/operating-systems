#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()

{
	pid_t p1;
	int y = 0;
	p1 = fork();

	if(p1>0)
	{
		printf("This is a parent process and ID = %d, y=%d\n", getpid(),y);
	}
	else if(p1==0)
	{
		y=y+1;
		printf("This is a child process and ID = %d, y=%d\n", getpid(),y);
	}
	else
	{
		printf("Fork() failed!!!\n");
	}
	return 0;
}