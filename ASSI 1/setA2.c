#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
	
	pid_t pid=fork();
	if(pid<0){
		printf("faild");
	}
	if(pid==0)
	{
		printf("chaild process id=%d\n",getpid);
		printf("nice value %d",nice(0));
		int nice_val=nice(-5);
		printf("current nice value after incress %d\n",nice_val);
		
	}
	else
		printf("parents pid = %d\n",getpid());
	
    return 0;
}


}
