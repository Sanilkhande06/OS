#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd[2];
	int ps[2];
	char childmsg[10];	
	int pid;
	int i;
	char buff[10];
	pipe(fd);
	pipe(ps);
	pid = fork();
	
	for(i=0;i<10;i++)
	{
			
		if(pid!=0)
		{
			if(i%2==0)
			{
				close(fd[1]);
				read(fd[0],buff,6);
				printf("\n\t\tChild: %s",buff);
			}
			else
			{
				printf("\n\t\tParent typing");
				scanf("%s",childmsg);
				close(ps[0]);
				write(ps[1],childmsg,6);
			}
			
		}
		else
		{
			if(i%2==1)
			{
				close(ps[1]);
				
				read(ps[0],buff,6);
				printf("\nParent: %s",buff);
			}
			else
			{
				printf("\nChild typing");
				scanf("%s",childmsg);
				close(fd[0]);
				write(fd[1],childmsg,6);
			}
		}
	}
	return 0;
}

