#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
int main()
{	
	int pid;
	
	printf("this is a parent before fork");

	pid=fork();
	
	printf("\n%d",pid);
	if(pid==0)
	{
	
		for(int i=0;i<10;i++)
		{
			printf("\nchild process getpied = %d",getpid());
			printf("\t%d",i+1);
			sleep(3);
		}
	}
	else
	{
		for(int i=10;i<20;i++)
		{
			if(i==15)
			{
				kill(pid,9);
			}
			printf("\n%d",getpid());
			printf("\t%d",i+1);
			sleep(3);
		}
	}
	
	return 0;
}

