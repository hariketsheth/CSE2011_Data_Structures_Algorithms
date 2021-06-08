#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minimum(char str[][50], int num)
{
    
    int i, min = strlen(str[0]);
    for (i=1; i<num; i++)
        if (min>strlen(str[i]))
            min = strlen(str[i]);
    return min;
}
  
bool checkPrefix(int num, int begin, int end, char str[][50])
{   int i,j;
    for (i=0; i<num; i++){
        for (j=begin; j<=end; j++){
            if (str[i][j] != str[0][j])
                return false;
        }
    }
    return true;
}
void LCP(char str[][50], int num)
{
    char sub[100],final[100];
    final[0] = '\0';
    int lower_b = 0, upper_b = minimum(str, num);
    while (lower_b <= upper_b )
    {
        int mid = ((upper_b  + lower_b +1 ) / 2);
        if (checkPrefix (num,lower_b, mid, str))
        {
            int c=0,length = ((mid+1)-lower_b )- lower_b ;
             while (c < length) {
              sub[c] = str[0][lower_b +c];
              c++;
            }
            sub[c] = '\0'; 
            if(strlen(sub)>0)
                strcat(final,sub);
            lower_b  = mid + 1;
        }
        else 
            upper_b  = mid - 1;
    }
    if(strlen(final)>0)
        printf("\nThe Longest Common Prefix (LCP) is: %s",final);
    else
        printf("-1");
}

int main()
{
    int num,i;
    printf("Enter the number of strings to be inputted: \n");
    scanf("%d",&num);
    char str[num][50];
    for(i=0;i<num;i++){
        scanf("%s",&str[i]);
    }
    LCP(str, num);
    return 0;
}

