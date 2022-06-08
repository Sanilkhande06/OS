#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
int main()
{	
	int pid1,pid2,pid3;
	
	printf("this is a parent before fork");

	pid1=fork();
	//pid2=fork();
	//pid3=fork();
	printf("\nparent = %d \t child %d",getpid(), pid1);
	if(pid1==0 )
	{
		
		for(int i=0;i<10;i++)
		{
			printf("\n%d",getpid());
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
				kill(pid1,9);
				//kill(pid2,9);
				//kill(pid3,9);
			}
			printf("\n%d",getpid());
			printf("\t%d",i+1);
			sleep(3);
		}
	}
	
	return 0;
}

