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
int quick_divide (struct product *p, int first, int last)
{
    char pivot_str[30];
    strcpy(pivot_str,p[last].name);
    int i = (first - 1); 
    for (int j = first; j <= last - 1; j++){
        if (strcmp(p[j].name,pivot_str)<0){
            i++; 
            struct product temp;
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
    struct product temp;
    temp = p[i+1];
    p[i+1] = p[last];
    p[last] = temp;
    return (i + 1);
}
 
int quick_sort(struct product *p, int first, int last)
{
    if (first < last)
    {
        int pivot = quick_divide(p, first, last);
        quick_sort(p, first, pivot - 1);
        quick_sort(p, pivot + 1, last);
    }
    else
        return -1;
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

    // Quick Sort of all the Products that were entered by User
    if(quick_sort(p,0, num-1)!=-1){
        print(p,num);
    
        // Binary Search for a Particular Product 
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
    }
    else{
        printf("Invalid Input for number of Products\n");
    }
    return 0;
}
