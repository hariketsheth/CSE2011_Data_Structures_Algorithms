#include<stdio.h>
int main(){
	int num,count_h=0,count_p=0,count_c=0;
	float temp;
	printf("Enter the number of places to be considered: ");
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		printf("Enter the temperature: ");
		scanf("%f",&temp);
		if(temp>=85){
			count_h+=1;
		}
		else if(temp<85 && temp>=60){
			count_p+=1;
		}
		else{
			count_c+=1;
		}
	}
	printf("Number of places (HOT): %d\n",count_h);
	printf("Number of places (PLEASANT): %d\n",count_p);
	printf("Number of places (COLD): %d\n",count_c);
	return 0;
}
