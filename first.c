#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	fork();
	fork();
	fork();
	fork();
	printf("Welcome to OS\n");
	return 0;
}