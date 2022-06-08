#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>
void *foo(void *arg);

char msg1[]="thread1";
char msg2[]="thread2";

int count =0;
pthread_mutex_t s;

int main()
{

	pthread_t th1,th2;
	int retval;
	void *retmsg;
	retval = pthread_mutex_init(&s,NULL);
	if(retval<0)
	{
		printf("sem_init failed");
		return 0;
	}
	retval = pthread_create(&th1,NULL,foo,(void *) msg1);
	if(retval!=0)
	{
		printf("pthread create failed");
		return 0;
	}
	retval=pthread_create(&th2,NULL,foo,(void *)msg2);
	if(retval!=0)
	{
		printf("pthread create failed");
		return 0;
	}
	
	retval = pthread_join(th1,&retmsg);
	
	if(retval!=0)
	{
		printf("join failed");
		return 0;
	}
	retval = pthread_join(th2,&retmsg);
	
	if(retval!=0)
	{
		printf("join failed");
		return 0;
	}
	
	printf("thread : %s",(char *)msg1);
	
	retval=pthread_mutex_destroy(&s);
	
	if(retval!=0)
	{
		printf("sem destroy failed");
		return 0;
	}
	return 0;
}

void *foo(void *arg)
{
	int retval;
	int i=0;
	while(i<=100)
	{
		pthread_mutex_lock(&s);
		
		printf("\nI am a %s and count is %d", (char *) arg, count++);
		
		pthread_mutex_unlock(&s);
		i++;
	}
	pthread_exit((void *)msg1);
}

				
	
