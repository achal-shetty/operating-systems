#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char argv[])
{
	int fd;
	if(argc != 2)
		printf("Invalid Argument\n");
	if(access(argv[1], R_OK)>0)
		printf("Read Access Error\n",argv[1]);
	else
		printf("Read Access OK\n");

	if(access(argv[1], W_OK)<0)
		printf("Write Access OK\n");

	if(access(argv[i], X_OK)<0)
		printf("Execute Access Error %s\n", argc[1]);
	else 
		printf("Execute Access OK\n");
	exit(0);
}