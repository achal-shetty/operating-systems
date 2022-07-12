#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[])

{
	int fd = creat(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(fd== -1)
		printf("Unable to create a file\n");
	for(int i=0; i<10; i++)
		write(fd, "Last Hands on Session",21);
	close(fd);
	if(truncate(argv[1],50)<0)
		printf("Unable to truncate\n");
	exit(0);
}