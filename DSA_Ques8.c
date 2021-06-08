#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Queue{
	int rear;
	int front;
	int *que;
	int time[10];
};
int IsEmpty (int rear, int front){
	if (front > rear) 
	//When the Stack has 0 elements then front =0 and rear =-1
	//Hence, checking for front > rear
		return true;
	else
	//When the Rear Value is Equal to front, then 1 element is present.
	//When Rear Value is Greater than front, then more than 1 elements are present.
		return false;
}
int IsFull (int rear){
	if (rear<9)
		return false;
	else
		return true;
}
int display(int *queue, int rear, int front){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d\t", queue[i]);
	}
	printf("\n");
}

//Function for calculating the Waiting time
// Time at which is printed - Time it was entered into the array
int waiting_time(int time[], int current_time, int pos){
	return current_time-time[pos];
}

//Function that prints the program stored in the front of queue
void printer(int *queue, int front, int rear, int time[], int current_time, int flag){
	if(flag==1){
	int i;
	for (i=front;i<=rear;i++){	
		printf("Program %d is in queue. (Waiting Time: %d)\n",queue[i],waiting_time(time,current_time,i));
		}
	}
	else{
		printf("Program %d is printed successfully (Waiting Time: %d)\n",queue[front],waiting_time(time,current_time,front));
	}
}

//Function that adds printing process to the queue
int Enqueue(int *queue, int rear, int current_time, int time[]){
	int element;
	printf("Enter the Program Number to be sent for printing: ");
	scanf("%d",&element);
	rear+=1;
	queue[rear]=element;
	time[rear]=current_time;
	return rear;
}

//Function that manages the queue after a program from the 'front' is printed by printer() function
int Dequeue(int *queue, int front, int rear, int time[], int current_time){
	int i=0;
	printer(queue, front, rear, time, current_time,0);
	for(i=front;i<=rear-1;i++){
		queue[i]=queue[i+1];
		time[i]= time[i+1];
	}
	rear-=1;
	return rear;
}
int main(){
	struct Queue q1;
	q1.rear=-1; 
	q1.front=0;
	char conti='Y';
	int current_time=1, option; 
	q1.que = (int *) malloc (10*sizeof(int));
	if(q1.que == NULL)
		printf("Memory was not allocated !");
	else{ 
		while(conti=='Y' || conti=='y'){
				printf("\n------------INDEX---------------\n");
				printf("1. Print a Program\n2. Add a program for printing\n3. See the Waiting List");
				printf("\nEnter the operation to be performed: ");
				scanf("%d",&option);
				switch(option){
					case 1: {
						if(IsEmpty(q1.rear,q1.front)==true){
							printf("No Printing Tasks are assigned. \n");
							current_time+=1;
						}
						else{
							q1.rear= Dequeue(q1.que, q1.front, q1.rear, q1.time, current_time);
							current_time+=4;
						}
						break;
					}
					case 2: {
						if(IsFull(q1.rear)==true){
							printf("Printer is busy at this moment. Please Wait....\n");
							printf("These tasks are scheduled at this moment: \n");
							display(q1.que, q1.rear, q1.front);
						}
						else
							q1.rear= Enqueue(q1.que, q1.rear, current_time, q1.time);
						current_time+=1;
						break;
					}
					case 3: {
						if(IsEmpty(q1.rear,q1.front)==true){
							printf("No Printing Tasks are added. Check Waiting List later.\n");
						}
						else{
							printer(q1.que, q1.front, q1.rear, q1.time, current_time,1);
						}
						current_time+=1;
						break;
					}
					default: {
						printf("Invalid Operation entered by user\n");
						current_time+=1;
						break;
					}
				}
				printf("Do you want to send requests to server? (Y/N): ");
				scanf("\n%c",&conti);
				if(conti=='N' || conti == 'n'){
					break;
			}
		}
		free(q1.que);
	}
	return 0;
}
