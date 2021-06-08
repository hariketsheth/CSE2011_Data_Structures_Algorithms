#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Priority_queue{
	int rear;
	int front;
	int *que;
};
int IsEmpty (int rear, int front){
	if ((front > rear))
		return true;
	else
		return false;
}
int IsFull (int rear){
	if (rear<9)
		return false;
	else
		return true;
}
void peek(int *queue, int front){
	printf("Next Task to be executed: %d\n", queue[0]);
}
int display(int *queue, int rear, int front){
	int i;
	printf("Task List\n----------\n");
	for(i=front;i<=rear;i++){
		printf("%d\n", queue[i]);
	}
	printf("\n");
}

int poll(int *queue, int front, int rear){
	int i;
	printf("Task %d is executed successfully \n",queue[front]);
	for(i=front;i<=rear-1;i++){
		queue[i]=queue[i+1];
		printf("Task %d is in queue. \n",queue[i]);
	}
	rear-=1;
	return rear;
}
int Add(int *queue, int rear, int front){
	int element,i,j;
	printf("Enter the Task to be added: ");
	scanf("%d",&element);
	rear+=1;
	queue[rear]=element; 
    for (i = front; i < rear; i++)   {  
    	for (j = front; j < rear-i; j++) { 
        if (queue[j] > queue[j+1]) {
        	int temp=queue[j];
        	queue[j]=queue[j+1];
        	queue[j+1]=temp;
		}
	}
}
	return rear;
}

int main(){
	struct Priority_queue q1;
	q1.rear=-1; 
	q1.front=0;
	char conti='Y';
	int option; 
	q1.que = (int *) malloc (10*sizeof(int));
	if(q1.que == NULL)
		printf("Memory was not allocated !");
	else{ 
		while(conti=='Y' || conti=='y'){
				printf("\n------------INDEX---------------\n");
				printf("1. Execute a Task\n2. Add a Task to Buffer\n3. Check the Task to be executed\n4. See the Waiting List");
				printf("\nEnter the operation to be performed: ");
				scanf("%d",&option);
				switch(option){
					case 1: {
						if(IsEmpty(q1.rear,q1.front)==true){
							printf("No Tasks are assigned. \n");
						}
						else{
							q1.rear= poll(q1.que, q1.front, q1.rear);
						}
						break;
					}
					case 2: {
						if(IsFull(q1.rear)==true){
							printf("System is busy at this moment. Please Wait....\n");
							printf("These tasks are scheduled at this moment: \n");
							display(q1.que, q1.rear, q1.front);
						}
						else
							q1.rear= Add(q1.que, q1.rear, q1.front);
						break;
					}
					case 3: {
						if(IsEmpty(q1.rear,q1.front)==true){
							printf("No Tasks are added. Check Buffer later.\n");
						}
						else{
							peek(q1.que, q1.front);
						}
						break;
					}
					case 4: {
						if(IsEmpty(q1.rear,q1.front)==true){
							printf("No Tasks are added. Check later.\n");
						}
						else{
							display(q1.que, q1.rear, q1.front);
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
		free(q1.que);
	}
	return 0;
}
