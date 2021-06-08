#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct product{
	char name[30];
	int percentage;
};

void print(struct product *p, int size){
	int i;
	printf("The sorted list of Products (along with percentages)\n");
	for(i=0;i<size;i++){
		printf("%s | Percentage: %d\n", p[i].name, p[i].percentage);
	}
}
void insertion_sort(struct product *p, int size){
	int i,j;
	struct product temp;
	for (i = 1; i <= size-1; i++){
	    j = i;
        while ( j > 0 && strcmp(p[j-1].name, p[j].name)>0){	        
            temp = p[j];
            p[j] = p[j-1];
            p[j-1] = temp;
            j--;
        }
    }
    print(p, size);
}
void selection_sort(struct product *p, int size){
	int count, i;
	for (count = 0; count < size - 1; count++) {
	    int min = count;
	    for (i = count + 1; i < size; i++) {
	      if (strcmp(p[min].name, p[i].name)>0)
	        min = i;
	    }
	    struct product temp;
	    temp = p[min];
	    p[min] = p[count];
	    p[count] = temp;
	}
	print(p, size);
}
int binary_search(struct product *p, char search[30], int low, int high){

	if (high >= low) {
	    int mid = low + (high - low) / 2;
	    if (strcmp(p[mid].name, search)==0)
	      return mid;
	    if (strcmp(p[mid].name,search)>0)
	      return binary_search(p, search, low, mid - 1);
	    return binary_search(p, search, mid + 1, high);
  }
  return -1;
}
int main(){
	int num, i, choice;
	printf("Enter the number of products: ");
	scanf ("%d", &num);
	struct product *p;
	p = (struct product *) malloc(num*sizeof(struct product));
	for(i=0;i<num;i++){
		printf("\n\nEnter the name of the product: ");
		scanf(" %[^\n]s",p[i].name);
		printf("Enter the product Percentage: ");
		scanf("%d",&p[i].percentage );
	}
	printf("------------INDEX------------------\n");
	printf("1. Perform sorting using Selection Sort\n2. Perform sorting using Insertion Sort\n");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			selection_sort(p, num);
			printf("\nFor Searching a Particular Product\n");
			char search[30];
			printf("Enter the product name to be searched: ");
			scanf(" %[^\n]s",search);
			if(binary_search(p, search, 0, num-1)==-1){
				printf("Product Not Found\n");
			}
			else{
				printf("Product Found !\n");
				int res = p[binary_search(p, search, 0, num-1)].percentage;
				printf("The Percentage for entered product is: %d\n", res);
			}
			break;
		}
		case 2:{
			insertion_sort(p, num);
			printf("\nFor Searching a Particular Product\n");
			char search[30];
			printf("Enter the product name to be searched: ");
			scanf(" %[^\n]s",search);
			
			if(binary_search(p, search, 0, num-1)==-1){
				printf("Product Not Found\n");
			}
			else{
				printf("Product Found !\n");
				int res = p[binary_search(p, search, 0, num-1)].percentage;
				printf("The Percentage for entered product is: %d\n", res);
			}
			break;
		}
		default:{
			printf("Invalid Choice");
			break;
		}
	}
}
