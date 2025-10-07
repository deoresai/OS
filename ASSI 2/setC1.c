#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
void typeline(char t2,char *t3,int n){
	FILE *fp;
	fp=fopen(t3,"r");
	if(fp==NULL){
		printf("File open error\n");
		return;
	}
	int ln=0;
	char ch;
	if(t2=='n'){
		while(ln<=n && (ch=fgetc(fp))!=EOF){
			printf("%c",ch);
			if(ch=='\n'){
			ln++;
			}
		}
	}
	if(t2=='-'){
		int total=0;
		while((ch=fgetc(fp))!=EOF){ 
			if(ch=='\n')
			{
				total++;
			}
		}
		rewind(fp);
		int skip=total-n,a=0;
		while(a<=skip && (ch=fgetc(fp))!=EOF){
			if(ch=='\n'){
			a++;}
			
		}
		while((ch=fgetc(fp))!=EOF){ printf("%c",ch);}
	}
}
int main(){
	char command[80],t1[20],t2[20],t3[20],t4[20];
	char n;
	system("clear");
	
	while(1){
		printf("\nmyshell$ ");
		fgets(command,80,stdin);
		n=sscanf(command,"%s%s%s%s",t1,t2,t3,t4);
		switch(n){
			case 1:
				execlp(t1,t1,(char *)NULL);
				printf("Error");
				break;		
		
			case 2:
				execlp(t1,t2,(char *)NULL);
				printf("Error");
				break;		
			case 3:
				if(strcmp(t1,"typeline")==0){
					if(t2[0]=='n'||t2[0]=='-'){
						int n;
						printf("How many lines\n");
						scanf("%d",&n);
						typeline(t2[0],t3,n);
					}				
				
				}else{
				execlp(t1,t3,(char *)NULL);
				printf("Error");
				}
				break;		
			case 4:
				execlp(t1,t4,(char *)NULL);
				printf("Error");
				break;		
		}
	}
	return 0;
}
