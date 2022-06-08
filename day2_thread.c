#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

void *foo(void *arg);

char msg[]="Hello Sunny Lokhande\n";
int main()
{
	pthread_t th1;
	int retval;
	void *retmsg;
	retval=pthread_create(&th1,NULL,foo,(void *) msg);
	if(retval!=0)
	{
		printf("\nthread create fail");
		return 0;
	}
	
	printf("\nI am in the parent process");
	retval=pthread_join(th1,&retmsg);
	if(retval!=0)
	{
		printf("\njoin failed ");
		return 0;
	}
	
	if(retval!=0)
	{
		printf("\njoin failed");
		return 0;
	}
	printf("\nthread:  %s", (char *)msg);
	return 0;
}

void *foo(void *arg)
{
	printf("\nthread is executing  %s",(char *)arg);
	sleep(3);
	strcpy(msg,"Bye Sunny");
	pthread_exit((void *)msg);
}

	
