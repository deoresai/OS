#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
void search(char *t2,char *t3,char *t4){
	FILE *fp;
	fp=fopen(t3,"r");
	if(fp==NULL){
		printf("File error\n");
		return;
	}
	char line[1024];
	int found=0,count=0;
	while(fgets(line,sizeof(line),fp)){
		if(strstr(line,t4)){
			found=1;
			count++;
			if(t2[0]=='f'){
				printf("%s",line);
				break;
			}else if(t2[0]=='a'){
				printf("%s",line);
			}
		}
	}
	if(t2[0]=='c'){
		printf("%d",count);
	}
	if(found==0){
	printf("NOT FOUND");
	}
}
int main(){
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n;
	system("clear");
	while(1){
		printf("\nmyshell$ ");
		fgets(command,80,stdin);
		n=sscanf(command,"%s%s%s%s",t1,t2,t3,t4);
		switch(n){
		
			case 1: 
				if(!fork()){
				execlp(t1,t1,(char *)NULL);
				printf("Error 1!");
				break;
				}
			case 2: 
				if(!fork()){
				execlp(t1,t2,(char *)NULL);
				printf("Error 2!");
				break;
				}
			case 3: 
				if(!fork()){
					execlp(t1,t2,t3,(char *)NULL);
					printf("Error 3!");
					break;
				}
			case 4: 
				if(strcmp(t1,"search")==0){
					search(t2,t3,t4);
				}else{
					if(!fork()){
					execlp(t1,t2,t3,t4,(char *)NULL);
					printf("Error 4!");
					
					}
				}		
		}		break;
	}
	
	return 0;
}
