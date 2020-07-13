#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
	int coef;
	int expon;
	struct poly *link;
};
typedef struct poly polyNode;
polyNode *a,*last_a,*b,*last_c,*node,*last_b,*c;
polyNode *getNode()
{
	polyNode *node;
	node=(polyNode*)malloc(sizeof(polyNode));
	if (!node)
	{
		
		printf("in sufficient memory\n");
		exit(0);
	}
	return node;
	
}
void attach(float coefficient,int exponent,polyNode **ptr)
{
	polyNode *temp;
	temp=getNode();
	temp->coef=coefficient;
	temp->expon=exponent;
	(*ptr)->link=temp;
	*ptr=temp;
	
}
int COMPARE(int a,int b)
{
	if (a==b)
	return 0;
	else if (a>b)
	return 1;
	else
	return -1;
}
void cpadd(polyNode *a,polyNode *b)
{
	int sum;
	while(a!=last_a->link && b!=last_b->link)
	{
		switch(COMPARE(a->expon,b->expon))
{
	case -1:
		attach(b->coef,b->expon,&last_c);
		b=b->link;
		
		case 0:
			sum=a->coef+b->coef;
			if (sum)
			attach(sum,a->expon,&last_c);
			a=a->link;
			b=b->link;
			break;
			case 1:
				attach(a->coef,a->expon,&last_c);
				a=a->link;
				
}
	}
	for(;a!=last_a->link;a=a->link)
	attach(a->coef,a->expon,&last_c);
	for(;b!=last_b->link;b=b->link)
	attach(b->coef,b->expon,&last_c);
	last_c->link=c;
}
void display_poly(polyNode *temp,polyNode*last)
{
	while(temp!=last->link)
	{
		printf("%d^%d",temp->coef,temp->expon);
		temp=temp->link;
		
	}
}

void peval(polyNode *temp,polyNode*last)
{
	int eval=0,x;
	printf("enter the value of x\n");
	scanf("%d",&x);
	while(temp!=last->link)
	{
	
eval=eval + temp->coef*pow(x,temp->expon);
temp=temp->link;
}
printf("the result of polynomial evaluation is : %d\n",eval);
}
main()
{
	int co,ex,n,m,i;
	printf("*****polynomial addition******");
	printf("enter the number of terms in 1st polynomial\n");
	scanf("%d",&m);
	printf("enter the number of terms in 2nd polynomial \n");
	scanf ("%d",&n);
	a=(polyNode*)malloc(sizeof(polyNode));
	last_a=a;
	last_a->link=last_a;
	b=(polyNode*)malloc(sizeof(polyNode));
	last_b->link=last_b;
	for(i=1;i<=m;i++)
	{
		printf("enter he %d term(coef and expon)of 1st polynomial\n");
		scanf("%d%d",&co,&ex);
		attach(co,ex,&last_a);
		last_a->link=a;
		
	}
	for (i=1;i<=n;i++)
	{
		printf("enter the %d term(coef and expon)of 2nd polynomial\n");
		scanf("%d%d",&co,&ex);
		attach(co,ex,&last_b);
		last_b->link=b;
		
	}
	printf("****1st polynomial a(x):");
	display_poly(c->link,last_a);
	printf("\n");
	printf("***2nd polynomial b(x):");
	display_poly(b->link,last_b);
	printf("\n");
	c=(polyNode*)malloc(sizeof(polyNode));
	last_c=c;
	cpadd(a->link,b->link);
	last_c=c;
	cpadd(a->link,b->link);
	printf("***result\n****");
	display_poly(a->link,b->link);
	printf("\n");
	printf("\n______________\n");
	printf("*****polynomial evaluation\n");
	peval(c->link,last_c);
}
