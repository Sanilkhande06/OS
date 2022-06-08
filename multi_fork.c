#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	
	printf("\nThis is before fork function");
	fork();
	fork();
	fork();
	printf("\nHello Sunny");
	printf("\n");
	return 0;
}


