//zombie process

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t p1 = fork();
	if(p1>0);
	{
		sleep(50);
		printf("Parent Executing\n");
	}
	else if(p1 == 0)
	{
		printf("Child Executed\n");
		exit(0);
	}
	return 0;
}