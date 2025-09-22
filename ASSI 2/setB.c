#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
void show(char t2,char *t3){
	
	DIR *dp;
	dp=opendir(t3);
	int count=0;
	struct dirent *entry;
	    if(dp == NULL)
    		{
        		printf("Directory %s not found\n", t3);
        		return;
    		}
    	while((entry=readdir(dp))!=NULL){
    		if(t2=='f'){
    		
    		printf("File = %s\n ",entry->d_name);
    		}
    		else if(t2=='n'){
    			count++;
    		}
    		else if(t2=='i'){
    		 printf("%s\t%ld\n", entry->d_name, (long)entry->d_ino);
    		}
    		
    	}
    	if(t2=='n'){
    	printf("Total number of entries is = %d\n",count);
    	}
    	
    	    closedir(dp);
	     
}
int main(){
		
		char line[80],t1[20],t2[20],t3[20],t4[20];
		char n;
		system("clear");
		while(1){
			printf("Myshell$");
			fgets(line,80,stdin);
			n=sscanf(line,"%s%s%s%s",t1,t2,t3,t4);
			switch(n){
				case 1:
					if(!(fork())){
						execlp(t1,t1,(char*)NULL);
						perror(t1);
					
					}		
					break ;
				case 2:
					
					if(!(fork())){
						execlp(t1,t2,(char*)NULL);
						perror(t1);
					
					}	
					break;
				case 3:
				
					if(strcmp(t1,"list")==0){
					show(t2[0],t3);
					}
					else{
					if(!(fork())){
						execlp(t1,t2,t3,(char*)NULL);
						perror(t1);
						}
					}
					break;
				case 4:
					
					if(!(fork())){
						execlp(t1,t2,t3,t4,(char*)NULL);
						perror(t1);
					
					}
					break;
				case 0:
					exit(0);
					
			}
		
		
		
		}



	return 0;
}
