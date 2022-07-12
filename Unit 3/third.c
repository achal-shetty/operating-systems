#include<stdio.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<string.h>

sem_t mutex;
void *my_thread1(void *arg)
{
	char s[] = "RCB";
	int l = strlen(s);
	for(int i=0; i<1; i++)
	{
		sem_wait(&mutex);
		putchar(s[i]);
		fflush(stdout);
		sleep(2);
		sem_post(&mutex);
	}
}

void *my_thread2(void *arg)
{
	char s[] = "ESCN";
	int l = strlen(s);
	for(int i = 0; i<l; i++)
	{
		sem_wait(&mutex);
		putchar(s[i]);
		fflush(stdout);
		sleep(2);
		sem_post(&mutex);
	}
}

int main()
{
	pthread_t t1, t2;
	sem_init(&mutex,0,1);
	pthread_create(&t1, NULL, my_thread1, NULL);
	pthread_create(&t2, NULL, my_thread2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	printf("\n");
	return 0;
}



//use gcc first.c -lpthread