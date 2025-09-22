#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t p=fork();
	if(p==0){
		sleep(2);
		printf("I am chaild having PID = %d\n",getpid());
		printf(" my parents PID is = %d\n",getppid());
		printf("Process is orphan");
	}
	else{		
		
		printf(" I am parent having PID = %d\n",getpid());
		printf("My chailds PID is = %d\n",p);
		
	    }
	return 0;
}
