#include <stdio.h>
int main(){
	int lr,vr,arith,pu_l,total;
	char name[20];
	printf("Enter the name of student: ");
	scanf("%s",&name);
	printf("Enter the marks of Logical Reasoning: ");
	scanf("%d",&lr);
	printf("Enter the marks of Verbal Reasoning: ");
	scanf("%d",&vr);
	printf("Enter the marks of Arithmetic Ability: ");
	scanf("%d",&arith);
	printf("Enter the marks of Puzzle Logic Test: ");
	scanf("%d",&pu_l);
	total=lr+vr+arith+pu_l;
	if(total>=150){
		printf("%s is eligible for giving Genius Level Test\n",name);
		if(lr>=30 && vr>=30 && arith>=30 && pu_l>=30){
			printf("%s is eligible for giving Genius Level-1 Test \n",name);
		}
		else{
			printf("%s is eligible for giving Genius Level-2 Test \n",name);
		}
	}
	else{
		printf("%s is rejected for Genius Level Test \n",name);
	}
	return 0;
}
