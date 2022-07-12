#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	for(i=0; i<argc; i++)
	{
		printf("%s", argv[i]);
		if(lstat(argv[i], &buf)<0)
		{
			printf("lstat error\n");
			continue;
		}
		if(S_ISREG(buf.st_mode))
			ptr = "Regular File";
		else if(S_ISDIR(buf.st_mode))
			ptr = "Directory";
		else if(S_ISCHR(buf.st_mode))
			ptr = "Character Special";
		else if(S_ISBLK(buf.st_mode))
			ptr = "Block File";
		else if(S_ISFIFO(buf.st_mode))
			ptr = "FIFO File";
		else
			ptr = "Unknown file";

		printf(": %s\n", ptr);
		printf("File Size: %ld\n", buf.st_size);

	}
}