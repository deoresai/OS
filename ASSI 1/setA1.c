#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){

	pid_t pid=fork();
	if(pid==0)
	{
		printf("I am child process %d \n",getpid());
	}else if(pid > 0)
		printf("I am parent process %d ",getpid());
	else
		printf("Faild\n");
	return 0;
}
