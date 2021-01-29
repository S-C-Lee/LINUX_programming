#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *t_function(void *ptr)
{
	char *message;
	message=(char *)ptr;
	printf("%s start\n",message);
	sleep(5);
	printf("%s end\n",message);
	return 0;
}

int main(int argc,char *argv[])
{
	pthread_t thread1, thread2;
	const char *message1 = "thread1";
	const char *message2 = "thread2";
	int ret, status;
	
	ret = pthread_create(&thread1,NULL, t_function,(void *)message1);
	if(ret <0)
		perror("thread create error");
	pthread_join(thread1,(void **)status);
	printf("thread1 return : %d\n",status);
	
	ret = pthread_create(&thread2,NULL,t_function,(void *)message2);
	if(ret <0)
		perror("thread2 create error");
	pthread_detach(thread2);

	sleep(10);
	return 0;
}
