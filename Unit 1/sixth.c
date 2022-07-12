#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t p1;
	p1= fork();
	int i = 0, y=0;
	if(p1>0)
	{
		wait(NULL);
		for(i=0; i<5; i++)
		{
			sleep(i);
			y=y-1;
			printf("Parent Process =%d, y=%d\n", getpid(), y);
		}
		
	}
	else if(p1==0)
	{
		for(i=0; i<5; i++)
		{
			sleep(i);
			y=y+1;
			printf("Child Process = %d; y=%d\n", getpid(), y);
		}
	}
	else
	{
		printf("Fork Failed!!!\n");
	}
	return 0;
}