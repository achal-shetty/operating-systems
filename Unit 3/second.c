
//use gcc first.c -lpthread


#include<stdio.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<string.h>

void *my_thread1(void *arg)
{
	char s[] = "RCB";
	int l = strlen(s);
	for(int i=0; i<1; i++)
	{
		putchar(s[i]);
		fflush(stdout);
		sleep(2);
	}
}

void *my_thread2(void *arg)
{
	char s[] = "ESCN";
	int l = strlen(s);
	for(int i = 0; i<l; i++)
	{
		putchar(s[i]);
		fflush(stdout);
		sleep(2);
	}
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, my_thread1, NULL);
	pthread_create(&t2, NULL, my_thread2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2,NULL);
	printf("\n");
	return 0;
}