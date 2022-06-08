#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
pid_t pid;
int main()
{
	//int pid;
	printf("\nthis is before fork function");
	pid=fork();
	
	if(pid==0)
	{
		printf("\nThis is a child process = %d:  parent -%d",getpid(), getppid());
	}
	else
	{
		printf("\nThis is a parent process %d",getpid());
	}
	printf("\n");
	return 0;
}

