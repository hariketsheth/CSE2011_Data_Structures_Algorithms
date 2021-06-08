#include <stdio.h>
int main(){
	int start[3][2], end[3][2], final[3][2];
	float profit[3], f_profit[2]={0};
	printf("Enter the stock at the start of the day: \n");
	for (int i=0; i<3;i++){
		for (int j=0;j<2;j++){
			scanf("%d",&start[i][j]);
		}
	}
	printf("Enter the stock at the end of the day: \n");
	for (int i=0; i<3;i++){
		for (int j=0;j<2;j++){
			scanf("%d",&end[i][j]);
		}
	}
	printf("Enter the profit rates for the drinks: \n");
	for(int i=0;i<3;i++){
		scanf("%f",&profit[i]);
	}
	for (int i=0; i<3;i++){
		for (int j=0;j<2;j++){
			final[i][j]=start[i][j]-end[i][j];
		}
	}
	for (int i=0;i<3;i++){
			f_profit[0]+=profit[i]*final[i][0];
			f_profit[1]+=profit[i]*final[i][1];
	}
	printf("Profit of drink of Brand A: %.2f\n",f_profit[0]);
	printf("Profit of drink of Brand B: %.2f\n",f_profit[1]);
	printf("Total profit at the end of the day: %.2f\n",f_profit[0]+f_profit[1]);
	return 0;
}
