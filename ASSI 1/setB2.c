#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
int main(){
	pid_t pid= fork();
	if(pid==0){
		wait(NULL);
		printf("I am orphon chaild: %d\n",getpid());
		printf("My parent pid is: %d\n",getppid());
		
	}else{
		printf("I amparent : %d\n",getpid());
		printf("Chaild id is %d\n",pid);
	
	}
	
	return 0;
}
