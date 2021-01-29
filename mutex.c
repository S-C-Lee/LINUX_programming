#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER;
int g_count = 0;

void *t_function(void *data)
{
	char *thread_name = (char *)data;
	pthread_mutex_lock(&mutex_lock);
	printf("%s start\n",thread_name);
	for (int i = 0; i < 1000000; i++)
		g_count++;
	printf("%s , g_count = %d\n",thread_name,g_count);
	pthread_mutex_unlock(&mutex_lock);
}

int main(int argc, int argv[])
{
	pthread_t p_thread1, p_thread2;
	int status;
	pthread_create(&p_thread1,NULL,t_function,(void *)"thread1");
	pthread_create(&p_thread2,NULL,t_function,(void *)"thread2");
	pthread_join(p_thread1, (void *)&status);
	pthread_join(p_thread2, (void *)&status);
}
