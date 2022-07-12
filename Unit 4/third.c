#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc, char *argv[i])
{
	struct dirent *dp;
	DIR *dir = opendir(argv[i]);
	if(!dir)
	{
		printf("Unable to open the directory\n");
		return 0;
	}

	while(dp = readdir(dir)!=NULL)
	{
		printf("%s\n", dp->d_name);
	}

	closedir(dir);
	return 0;

}