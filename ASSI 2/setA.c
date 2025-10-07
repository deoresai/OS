#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
#include<stdlib.h>
void count(char t2,char *t3){

	FILE *fp=fopen(t3,"r");
	int c=0,w=0,l=0;
	char ch;
	if(fp==NULL){
		printf("File open error\n");
		return;
	}
	while((ch=fgetc(fp))!=EOF){
		c++;
		if(ch==' ' || ch==','|| ch=='.'){
			w++;
		}else if(ch=='\n'){
			l++;
		}
	}
	if(t2=='c'){
		printf("charector count is: %d",c);
	}else if(t2=='w'){
		printf("world count is: %d",w);
	}else if(t2=='l'){
		printf("Line count is: %d",l);
	}else printf("Wrong input");
		
}
int main(){
	char command[80],t1[20],t2[20],t3[20],t4[20];
	system("clear");
	char n;
	while(1){
		printf("\n$Myshell ");
		fgets(command,80,stdin);
		n=sscanf(command,"%s%s%s%s",t1,t2,t3,t4);
		switch(n){
			case 1:
				if(!fork()){
					execlp(t1,t1,(char*)NULL);
					printf("File does not open\n");
				}	
				break;
			case 2:
				if(!fork()){
					execlp(t1,t2,(char*)NULL);
					printf("File does not open\n");
				}	
				break;
			case 3:
				if(strcmp(t1,"count")==0){
					count(t2[0],t3);
					
				}
				else if(!fork()){
					execlp(t1,t3,(char*)NULL);
					printf("File does not open\n");
				}					
				break;
			case 4:
				if(!fork()){
					execlp(t1,t4,(char*)NULL);
					printf("File does not open\n");
				}				
				break;
		}
	}
	return 0;
}
