#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
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
			if(i>6)
			{
				printf("\nExiting child process using exit(0)");
				exit(0);	
			}
		}
	}
	else
	{
		int cpid;
		int status;
		sleep(6);
		cpid = wait(&status);
		printf("\nchild process %d is closed with %d status",cpid,WEXITSTATUS(status));
		for(int i=10;i<20;i++)
		{
			
			printf("\nparent %d : \t%d",getpid(),i+1);
			
		}
	}
	
	return 0;
}

