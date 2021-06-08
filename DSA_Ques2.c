#include <stdio.h>
int main(){
	float BMI, height, weight;
	char name[20];
	printf("Enter the name of the patient: ");
	scanf("%s",&name);
	printf("Enter the weight (in kg): ");
	scanf("%f",&weight);
	printf("Enter the height (in meters): ");
	scanf("%f",&height);
	BMI=weight/(height*height);
	if(BMI>25){
		printf("%s is Obese and Not Healthy",name);
	}
	else{
		printf("%s is Healthy",name);
	}
	return 0;
}
