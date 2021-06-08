#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
typedef struct InfixToPostfix{
	char stack[100];
	int top = -1;
} InfixToPostfix;

InfixToPostfix var1;
char pop()
{
    if(var1.top == -1)
        return -1;
    else
        return var1.stack[var1.top--];
}
void push(char ch)
{	if(strlen(var1.stack)<SIZE)
    	var1.stack[++var1.top] = ch;
}
int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/' || ch == '%')
        return 2;
    if(ch == '^')
    	return 3;
    return 0;
}
int main()
{
    char *exp, ch, expression[100];
    printf("Enter the Infix Expression : ");
    scanf("%s",expression);
    printf("The Converted Postfix Expression is: ");
    exp = expression;
    
    while(*exp != '\0')
    {
        if(isalnum(*exp))
            printf("%c ",*exp);
        else if(*exp == '(')
            push(*exp);
        else if(*exp == ')')
        {
            while((ch = pop()) != '(')
                printf("%c ", ch);
        }
        else
        {
            while(precedence(var1.stack[var1.top]) >= precedence(*exp))
                printf("%c ",pop());
            push(*exp);
        }
        exp++;
    }
    while(var1.top != -1)
    {
        printf("%c ",pop());
    }
	return 0;
}
