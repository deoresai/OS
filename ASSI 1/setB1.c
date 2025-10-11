#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
void display(int a[],int n){

	for(int i=0; i<n; i++){
		printf("%d\t",a[i]);
	}

}
void bubble(int a[],int n){
	
	int i,j,temp;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		
		}
	}
	display(a,n);
}
void insertion(int a[],int n){

	int temp,i,j;
	for(i=1; i<n; i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && temp<= a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	display(a,n);
}
int main(){
	int n;
	printf("How many no\n");
	scanf("%d",&n);	
	int i,a[n];
	printf("Enter %d elements\n",n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	
	pid_t pid=fork();
	if(pid==0){
		printf("Sorted by bubble sort\n");
		bubble(a,n);
	}else{
		printf("Sorder by insertion sort\n");
		insertion(a,n);
	}


	return 0;
}
