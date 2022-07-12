#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int rv=0;
	rv = setuid(1000);
	if(rv<0)
		printf("Error in setting user id\n");
	rv = setgid(2000);

	if(rv<0)
		printf("Error in setting group id\n");

	printf("real id = %d, effective id = %d\n", getuid(), geteuid());
	exit(0);
}