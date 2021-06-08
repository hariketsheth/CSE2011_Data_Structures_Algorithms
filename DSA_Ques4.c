#include<stdio.h>
int main(){
	int num_a[10][2];
	for (int i=0;i<10;i++){
		scanf("%d",&num_a[i][0]);
		if(num_a[i][0]%2==0){
			num_a[i][1]=1;
		}
		else{
			num_a[i][1]=0;
		}
	}
	printf("The Even numbers inputted by user: \n");
	for (int i=0;i<10;i++){
		if(num_a[i][1]==1){
			printf("%d\t",num_a[i][0]);
		}
	}
	printf("\nThe Odd numbers inputted by user: \n");
	for (int i=0;i<10;i++){
		if(num_a[i][1]==0){
			printf("%d\t",num_a[i][0]);
		}
}
	return 0;
}
