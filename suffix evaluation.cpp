#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int op(char symbol,int op1,int op2)
{
	switch(symbol)
	{
		case'+':return op1+op2;
		case'-': return op1-op2;
		case'*': return op1*op2;
		case '/': return op1/op2;
		case '%' : return op1%op2;
		case '^': return pow(op1,op2);
		
	}
	return 0;
}
void push(int item,int *top,int s[])
{
	*top=*top+1;
	s[*top]=item;
}
int pop(int *top,int s[])
{
	int item;
	item=s[(*top)];
	*top=*top-1;
	return item;
}
int isdigit(char symbol)
{

return(symbol>='0' && symbol<='9');
}
main()
{
	int op1,op2,res;
	int s[10];
	char postfix[10];
	int top=-1;
	char symbol;
	int i;
	printf("enter the valid postfix expression\n");
	scanf("%s",postfix);
	for (i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		if (isdigit(symbol))
		{
			push(symbol-'0',&top,s);
			
		}
		else
		{
			op2=pop(&top,s);
			op1=pop(&top,s);
			res=op(symbol,op1,op2);
			push(res,&top,s);
			
		}
	}
	res=pop(&top,s);
	printf("the result is %d\n",res);
}
