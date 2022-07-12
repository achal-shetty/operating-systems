#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)


int main(int argc, char *argv[])
{
	umask(S_IRGRP | S_IWGRP);
	if(creat(argv[1], RWRWRW)<0)
		printf("Unable to create the file\n");
	exit(0);
}