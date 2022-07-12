#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t p1, p2;
	p1 = fork();
	int y=0;

	if(p1>0)
	{
		wait(NULL);
		y=y-1;
		printf("This is parent process PID = %d, y = %d\n", getpid(), y);
	}
	else if(p1==0)
	{
		p2= fork();
		if(p2>0)
		{
			wait(NULL);
			printf("My Parent ID = %d\n", getppid());		
		}
		else if(p2==0)
		{
			y=y+5;
			printf("Grand Child ID = %d\n, PPID = %d, y = %d\n", getpid(), getppid(),y);
			exit(0);
		}
	y=y+1;
	printf("Child Process = %d, PPID = %d, y=%d\n", getpid(), getppid(),y);
	}

	else
	{
		printf("Fork Failed!!\n");
	}

}