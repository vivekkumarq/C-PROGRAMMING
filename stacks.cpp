#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
int s[MAX],top=-1;
void push(int ele)
{
	if(top==MAX-1)
	printf("stack overflow\n");
	else
	s[++(top)]=ele;
	
}
void pop()
{
	int ele;
	if(top==-1)
	printf("stack underflow\n");
	else
	{
		printf("popped element=%d",s[top]);
		top--;
		
	}
}
void display()
{
	int
}
