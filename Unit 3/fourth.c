#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

pthread_t t1, t2;
pthread_mutex_t first_mutex, second_mutex;

void *my_func1(void *arg)
{
	pthread_mutex_lock(&first_mutex);
	sleep(5);
	pthread_mutex_lock(&second_mutex);
	printf("Ee sala cup namde...\n");
	sleep(5);
	printf("Ee sala cup namde....2\n");
	pthread_mutex_unlock(&first_mutex);
	sleep(5);
	pthread_mutex_unlock(&second_mutex);
	pthread_exit(0);
}

void *my_func2(void *arg)
{
	pthread_mutex_lock(&second_mutex);
	sleep(5);
	pthread_mutex_lock(&first_mutex);
	printf("Ee sala cup namde...\n");
	sleep(5);
	printf("Ee sala cup namde....2\n");
	pthread_mutex_unlock(&first_mutex);
	sleep(5);
	pthread_mutex_unlock(&second_mutex);
	pthread_exit(0);
}

int main()
{
	pthread_mutex_init(&first_mutex, NULL);
	pthread_mutex_init(&second_mutex, NULL);

	pthread_create(&t1, NULL, &my_func1, NULL);
	pthread_create(&t2, NULL, &my_func2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&first_mutex);
	pthread_mutex_destroy(&second_mutex);
	return 0;
}