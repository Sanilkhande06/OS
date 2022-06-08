#include<stdio.h>
#include<unistd.h>
char msg[50];
char childmsg[50];
int main()
{

	int fd[2];
	int n=1;
	pipe(fd);
	while(n==5)
	{
		printf("\nParent:  ");
		scanf("%s",msg);
		write(fd[1],msg,20);
		read(fd[0],childmsg,20);
		n++;
	}
	return 0;
}

