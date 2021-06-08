#include <stdio.h>

void MERGE(int x[], int first, int mid, int last) {
    int first1 = first, last1 =mid, first2 = mid +1,last2 = last;
    int i = first;
    int temp[100];
    while (first1<=last1 && first2<=last2) {
        if(x[first1]<x[first2]){
            temp[i]=x[first1];
            first1= first1+1;
            i+=1;
        }
        else if(x[first1]>x[first2]){ 
            temp[i]=x[first2];
            first2=first2+1;
            i+=1; 
        }
        else if(x[first1]==x[first2]){
            temp[i]=x[first1];
            temp[i+1]=x[first2];
            first1=first1+1;
            first2=first2+1;
            i+=2; 
        }
    }
    while (first2<=last2){
        temp[i]=x[first2];
        first2=first2+1;
        i=i+1;
    }

    while (first1<=last1){
        temp[i]=x[first1];
        first1=first1+1;
        i=i+1;
    }

    for(int j=first; j<=last; j++)
        x[j]=temp[j];
}
void MERGE_SORT(int a[], int first, int last) {
    if (first < last) {
        int mid = (last + first) / 2;
        MERGE_SORT(a, first, mid);
        MERGE_SORT(a, mid + 1, last);
        MERGE(a, first, mid, last);
    }
}
    
    
int main() {
    int num;
    printf("Enter the number of elements to be considered: ");
    scanf("%d",&num);
    int a[num];
    for(int i=0; i<num; i++)
    scanf("%d",&a[i]);

    printf("\nOriginal array: \n");
    for (int i = 0; i < num; i++)
    printf("%d\t", a[i]);
    printf("\n");
    MERGE_SORT(a, 0, num - 1);
    printf("Sorted array (After Merge Sorting): \n");
    for (int i = 0; i < num; i++)
    printf("%d\t", a[i]);
}
