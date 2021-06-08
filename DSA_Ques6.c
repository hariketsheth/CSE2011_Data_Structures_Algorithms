#include <stdio.h>
int IsEmpty (int stack[], int count){
	if (stack[0]==-1 && count==0){
		return 1;
	}
	else{
		return 0;
	}
}
int IsFull (int stack[], int count, int SIZE){
	if (count<=SIZE-1){
		return 0;
	}
	else{
		return 1;
	}
}
int push(int stack[], int count){
	int element;
	printf("Enter the element to be inserted in the push: ");
	scanf("%d",&element);
	stack[count]=element;
	count+=1;
	return count;
}
int pop(int stack[], int count, int pos){
	int i;
if(pos<=count){
	for(i=count-pos;i<count-1;i++){
		stack[i]=stack[i+1];
		
	} 
	count-=1;
	}
	else{
		printf("Index out of range. Pop Operation cannot be performed\n");
	}
	return count;
}
int s_top(int stack[], int count){
	printf("The Top element of the Stack is: %d\n",stack[count-1]);
}
int display(int stack[], int count, int SIZE){
	int i;
	printf("The Stack is: \n");
	for(i=0;i<count;i++){
		printf("%d\t", stack[i]);
	}
	printf("\n");
}
int main(){
	int SIZE, pos;
	printf("Enter the number of elements: ");
	scanf("%d",&SIZE);
	int stack[100]={-1}, top=-1, option, conti='Y', count=0;
	while(conti=='Y' || conti=='y'){
		printf("------------INDEX---------------\n");
		printf("1. Push Operation\n2. Pop Operation\n3. IsEmpty\n4. IsFull\n5. Top\n6. Display");
		printf("\nEnter the operation to be performed: ");
		scanf("%d",&option);
		switch(option){
			case 1: {
				if(IsFull(stack,count,SIZE)==1){
					printf("Push Operation cannot be performed\n");
					printf("Stack is Full\n");
				}
				else{
					count= push(stack, count);
				}
				break;
			}
			case 2: {
				if(IsEmpty(stack, count)==1){
					printf("Pop Operation cannot be performed\n");
					printf("Stack is Empty\n");
				}
				else{
					printf("Enter the position of the element to be popped: ");
					scanf("%d",&pos);
					count= pop(stack, count, pos);
				}
				break;
			}
			case 3: {
				if(IsEmpty(stack, count)==1){
					printf("Yes, Stack is EMPTY !\n");
				}
				else{
					printf("No, Stack is not EMPTY !\n");
				}
				break;
			}
			case 4: {
				if(IsFull(stack, count, SIZE)==1){
					printf("The Stack is FULL !\n");
				}
				else{
					printf("The Stack is not FULL !\n");
				}
				break;
			}
			case 5:{
				if(IsEmpty(stack, count)==1){
					printf("The Top element is not yet added.\n");
				}
				else{
					s_top(stack, count);
				}
				break;
			}
			case 6:{
				if(IsEmpty(stack, count)==1){
					printf("The Stack cannot be displayed.\n");
				}
				else{
					display(stack, count, SIZE);
				}
				break;
			}
			default: {
				printf("Invalid Operation entered by user\n");
				break;
			}	
		}
		printf("Do you want to continue? (Y/N): ");
		scanf("\n%c",&conti);
		if(conti=='N' || conti == 'n'){
			break;
		}
	}
	return 0;
}
